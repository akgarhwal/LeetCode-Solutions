/*
Problem Title: 278 - First Bad Version
Lang: C
Runtime: 1148 ms
Memory: 5.1 MB
Problem Url: https://leetcode.com/problems/first-bad-version
Submission Url: https://leetcode.com/problems/first-bad-version/submissions/332662616
*/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
 
    while(isBadVersion(n) == true){
        n--;
    }
    return n+1;
}