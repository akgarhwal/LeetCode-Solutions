# Bash script to fetch submissions from leetcode.com and push it to github

# Run python3 script to fetch recent subsmissons
cd ~/github/LeetCode-Solutions/scripts/

echo -e "\n\n" >> leetcode-submissions-downloader.log
python3 leetcode-submissions-downloader.py -c 99 >> leetcode-submissions-downloader.log


# Now do git steps
cd ../

today=`date`
branch=`date +"%d-%m-%Y"`

git pull 
git checkout -b "leetcode-$branch"

git add scripts/*.log
git add Solutions/
git commit -m "Submission added on $today"
git push -u origin HEAD

git checkout main

echo "Completed for $today."

