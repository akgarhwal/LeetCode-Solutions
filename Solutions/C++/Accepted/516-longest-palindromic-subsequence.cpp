/*
Problem Title: 516 - Longest Palindromic Subsequence
Lang: C++
Runtime: 134 ms
Memory: 73 MB
Problem Url: https://leetcode.com/problems/longest-palindromic-subsequence
Submission Url: https://leetcode.com/problems/longest-palindromic-subsequence/submissions/933593788
*/

class Solution {
public:

    int longestPalindromeSubseq(string s) {
        
        vector<vector<int>> dp(s.size(), vector(s.size(), 0));

        for (int i = s.size() - 1; i >= 0; i--) {
            dp[i][i] = 1;

            for (int j = i + 1; j < s.size(); j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[0][s.size()-1];
    }
};