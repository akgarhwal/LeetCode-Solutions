/*
Problem Title: 1312 - Minimum Insertion Steps to Make a String Palindrome
Lang: C++
Runtime: 63 ms
Memory: 28.4 MB
Problem Url: https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome
Submission Url: https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/submissions/937746428
*/

class Solution {
public:

    int solve(string& s, int l, int r, vector<vector<int>>& dp) {
        if(l >= r) {
            return 0;
        }

        if(dp[l][r] != -1){
            return dp[l][r];
        }

        if(s[l] == s[r]) {
            return dp[l][r] = solve(s, l+1, r-1, dp); 
        }

        return dp[l][r] = 1 + min( solve(s, l, r-1, dp), solve(s, l+1, r, dp) );
    }

    int minInsertions(string s) {
        
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));

        return solve(s, 0, s.size()-1, dp);
    }
};