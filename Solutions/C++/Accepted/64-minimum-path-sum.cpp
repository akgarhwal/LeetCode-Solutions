/*
Problem Title: 64 - Minimum Path Sum
Lang: C++
Runtime: 8 ms
Memory: 8.4 MB
Problem Url: https://leetcode.com/problems/minimum-path-sum
Submission Url: https://leetcode.com/problems/minimum-path-sum/submissions/326467278
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 0) return 0;
        int m = grid[0].size();
        for(int row = 1; row < n; row++){
            grid[row][0] += grid[row-1][0];
        }
        for(int col = 1; col < m; col++){
            grid[0][col] += grid[0][col-1];
        }
        for(int row = 1; row < n; row++){
            for(int col = 1; col < m; col++){
                grid[row][col] += min(grid[row-1][col], grid[row][col-1]);
            }    
        }
        return grid[n-1][m-1];
    }
};