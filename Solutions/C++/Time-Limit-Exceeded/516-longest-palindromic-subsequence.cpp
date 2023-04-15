/*
Problem Title: 516 - Longest Palindromic Subsequence
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/longest-palindromic-subsequence
Submission Url: https://leetcode.com/problems/longest-palindromic-subsequence/submissions/933590726
*/

class Solution {
public:

    int solve(string s, int i, int j, vector<vector<int>>& dp) {

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        if(i > j) {
            return 0;
        }

        if(i == j) {
            return 1;
        }

        if(s[i] == s[j]) {
            dp[i][j] = solve(s, i+1, j-1, dp) + 2;
        } else {
            dp[i][j] = max( solve(s, i+1, j, dp), solve(s, i, j-1, dp));
        }

        return dp[i][j];
    }

    int longestPalindromeSubseq(string s) {
        
        vector<vector<int>> dp(s.size(), vector(s.size(), -1));

        return solve(s, 0, s.size()-1, dp);
    }
};