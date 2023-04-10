/*
Problem Title: 304 - Range Sum Query 2D - Immutable
Lang: C++
Runtime: 418 ms
Memory: 142.6 MB
Problem Url: https://leetcode.com/problems/range-sum-query-2d-immutable
Submission Url: https://leetcode.com/problems/range-sum-query-2d-immutable/submissions/930830594
*/

class NumMatrix {
    vector<vector<int>> dp;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        dp.resize(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));

        for (int r = 0; r < matrix.size(); r++) {
            for (int c = 0; c < matrix[0].size(); c++) {
                dp[r + 1][c + 1] = dp[r + 1][c] + dp[r][c + 1] + matrix[r][c] - dp[r][c];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2 + 1][col2 + 1] - dp[row1][col2 + 1] - dp[row2 + 1][col1] + dp[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */