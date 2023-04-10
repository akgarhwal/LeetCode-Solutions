/*
Problem Title: 63 - Unique Paths II
Lang: C++
Runtime: 0 ms
Memory: 7.8 MB
Problem Url: https://leetcode.com/problems/unique-paths-ii
Submission Url: https://leetcode.com/problems/unique-paths-ii/submissions/930827683
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        

        for(int i = 0; i < n; i++) {
            if(obstacleGrid[0][i]) {
                dp[0][i] = 0;
            } else {
                dp[0][i] =  i > 0 ? dp[0][i-1] : 1;
            }
        }
        for(int i = 0; i < m; i++) {
            if(obstacleGrid[i][0]) {
                dp[i][0] = 0;
            } else {
                dp[i][0] = i > 0 ? dp[i-1][0] : 1;
            }
        }
        
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(obstacleGrid[i][j]){
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};