/*
Problem Title: 583 - Delete Operation for Two Strings
Lang: C++
Runtime: 716 ms
Memory: 384.6 MB
Problem Url: https://leetcode.com/problems/delete-operation-for-two-strings
Submission Url: https://leetcode.com/problems/delete-operation-for-two-strings/submissions/489959601
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1, -1));
        return fun(word1, word2, 0, 0, dp);
    }
    
    int fun(string s1, string s2, int i, int j, vector<vector<int>> &dp){
        if(i >= s1.size() and j >= s2.size()){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }        
        if(i >= s1.size()){
            return dp[i][j] = fun(s1, s2, i, j+1, dp) + 1;
        }
        if(j >= s2.size()){
            return dp[i][j] = fun(s1, s2, i+1, j, dp) + 1;
        }
        
        if(s1[i] == s2[j]){
            return dp[i][j] = fun(s1, s2, i+1, j+1, dp);
        }
        
        return dp[i][j] = min(fun(s1, s2, i+1, j, dp), fun(s1, s2, i, j+1, dp)) + 1;
    }
};