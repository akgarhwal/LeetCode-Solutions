/*
Problem Title: 1143 - Longest Common Subsequence
Lang: C++
Runtime: 24 ms
Memory: 12.5 MB
Problem Url: https://leetcode.com/problems/longest-common-subsequence
Submission Url: https://leetcode.com/problems/longest-common-subsequence/submissions/330307640
*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> memo(m+1, vector<int>(n+1,0));
        
        for(int i = 1; i<= m; i++){
            for(int j = 1; j <= n; j++){
                if(text1[i-1] == text2[j-1]){
                    memo[i][j] = memo[i-1][j-1] + 1;
                }
                else{
                    memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
                }
            }
        }
        return memo[m][n];
    }
};