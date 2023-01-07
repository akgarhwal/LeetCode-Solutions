# Bash script to fetch submissions from leetcode.com and push it to github

# Run python3 script to fetch recent subsmissons
echo "\n\n" >> leetcode-submissions-downloader.log
python3 leetcode-submissions-downloader.py >> leetcode-submissions-downloader.log


# Now do git steps
cd ../

git add scripts/*.log

git add Solutions/

today=`date`

git commit -m "$today - submissions"

git push


echo "'git push' Completed\n\n" >> leetcode-submissions-downloader.log
