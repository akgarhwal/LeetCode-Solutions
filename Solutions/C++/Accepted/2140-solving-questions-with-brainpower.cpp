/*
Problem Title: 2140 - Solving Questions With Brainpower
Lang: C++
Runtime: 386 ms
Memory: 123.1 MB
Problem Url: https://leetcode.com/problems/solving-questions-with-brainpower
Submission Url: https://leetcode.com/problems/solving-questions-with-brainpower/submissions/948793547
*/

class Solution {
public:

    long dfs(vector<vector<int>>& questions, int i, vector<long>& dp) {
        if (i >= questions.size()) {
            return 0;
        }
        if (dp[i] != 0) {
            return dp[i];
        }
        long points = questions[i][0];
        int skip = questions[i][1];

        dp[i] = max(points + dfs(questions, i + skip + 1, dp), dfs(questions, i + 1, dp));

        return dp[i];
    }

    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long> dp(n, 0);
        
        return dfs(questions, 0, dp);
    }
};