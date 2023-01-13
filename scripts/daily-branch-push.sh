# Bash script to fetch submissions from leetcode.com and push it to github

# Get Latest changes from remote repo
cd ~/github/LeetCode-Solutions/
git pull

# Run python3 script to fetch recent subsmissons
cd scripts/

echo -e "\n\n" >> leetcode-submissions-downloader.log
python3 leetcode-submissions-downloader.py -c 99 >> leetcode-submissions-downloader.log


# Now do git steps
cd ../

today=`date`
branch=`date +"%d-%m-%Y"`

git checkout -b "leetcode-$branch"

git add scripts/*.log
git add Solutions/
git commit -m "Submission added on $today"
git push -u origin HEAD

git checkout main

echo "Completed for $today."

