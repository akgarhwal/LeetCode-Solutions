# This script is not fully ready to use.
# TODO: handle case where no submission OR no accepeted submission for a question
# TODO: handle already fetched submissions for questions by storing some data in file.


# Download all submissions from leetcode

# Api to download all questions meta data from leetcode
# ```
# curl --location --request GET 'https://leetcode.com/api/problems/all/' \
# --header 'Cookie: <YOUR_COOKIE_VALUE>'
# ```

# global vars
let question__title_slug_list
let accepted_submission

# Define a function called "getAllQuestionsTitleSlug"
function getAllQuestionTitleSlug {
    all_questions_meta_data_json_file_name="LeetCodeAllProblems.json"

    question__title_slug_list=$(jq -r '.stat_status_pairs[].stat.question__title_slug' $all_questions_meta_data_json_file_name)
    # echo $question__title_slug_list

    # Iterate over the question__title_slug_list list
    # for question__title_slug in $question__title_slug_list; do
    #     echo $question__title_slug
    # done

    # echo $question__title_slug_list
}

function fetchSubmissionsAndFindOneAcceptedSubmission {
    question__title_slug=$1
    response=$(curl --location --request GET https://leetcode.com/api/submissions/${question__title_slug} \
    --header 'Cookie: <YOUR_COOKIE_VALUE>')

    # echo $response
    # Extract the array of submissions from the JSON string
    # submissions=$(echo $response | jq -c '.submissions_dump[]')

    # echo "$submissions | jq"

    accepted_submission=$(echo $response | jq -c '[.submissions_dump[] | select(.status_display == "Accepted")]'[0])
}

function writeSubmissionToFile {

    URL_Prefix="https://leetcode.com/problems"

    submission=$accepted_submission
    #echo $submission

    if [ "$submission" == null ]; then
        return
    fi

    sid=$(echo $submission | jq -r '.id')
    lang=$(echo $submission | jq -r '.lang')
    runtime=$(echo $submission | jq -r '.runtime')
    title=$(echo $submission | jq -r '.title')
    title_slug=$(echo $submission | jq -r '.title_slug')
    memory=$(echo $submission | jq -r '.memory')
    code=$(echo $submission | jq -r '.code')
    
    file_ext=$lang
    if [ $file_ext == "csharp" ]; then
        file_ext="cs"
    fi

    file_name="../${title_slug}.${file_ext}"
    #echo $file_name

    touch "${file_name}"

    content="/* Question: $title\n * Lang: $lang\n * Runtime: $runtime\n * Memory: $memory\n * Question Url: ${URL_Prefix}/${title_slug}\n * Submission Url: ${URL_Prefix}/${title_slug}/submissions/${sid}\n */"
    content+="\\n\\n$code" 
   
    # write to file
    echo -e "${content}" > $file_name

    # Format code using clang-format tool
    clang-format -i $file_name
    
}

# Call getAllQuestionTitleSlug
getAllQuestionTitleSlug

count=0
# Iterate over the question__title_slug_list list
for question__title_slug in $question__title_slug_list; do
    #echo $question__title_slug
    count=$((count+1))

    fetchSubmissionsAndFindOneAcceptedSubmission $question__title_slug
    writeSubmissionToFile

    if [ $((count % 10)) -eq 0 ]; then
        echo "$count/2519"
    fi

    sleep 0.5
done






