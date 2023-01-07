# Bash script to fetch submissions from leetcode.com and push it to github

# Run python3 script to fetch recent subsmissons
echo -e "\n\n" >> leetcode-submissions-downloader.log
python3 leetcode-submissions-downloader.py >> leetcode-submissions-downloader.log


# Now do git steps
cd ../

git add scripts/*.log

git add Solutions/

today=`date`

git commit -m "Submission added on $today"

git push


echo -e "'git push' Completed\n\n" >> scripts/leetcode-submissions-downloader.log
