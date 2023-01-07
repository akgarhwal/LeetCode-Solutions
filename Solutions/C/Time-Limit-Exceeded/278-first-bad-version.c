/*
Problem Title: 278 - First Bad Version
Lang: C
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/first-bad-version
Submission Url: https://leetcode.com/problems/first-bad-version/submissions/332664136
*/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    int res = 1;
    while(isBadVersion(res) == false){
        res++;
    }
    return res;
}