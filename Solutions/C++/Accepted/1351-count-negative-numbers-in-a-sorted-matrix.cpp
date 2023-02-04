/*
Problem Title: 1351 - Count Negative Numbers in a Sorted Matrix
Lang: C++
Runtime: 13 ms
Memory: 10.5 MB
Problem Url: https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix
Submission Url: https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/submissions/890403484
*/

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0, R = grid.size(), C = grid[0].size();
        int j = C-1;
        for(int i = 0; i < R; i++) {
            while(j >= 0 and grid[i][j] < 0) {
                j--;
            }
            ans += (C - j - 1);
        }
        return ans;
    }
};