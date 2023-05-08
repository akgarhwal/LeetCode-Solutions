/*
Problem Title: 48 - Rotate Image
Lang: C++
Runtime: 0 ms
Memory: 7.2 MB
Problem Url: https://leetcode.com/problems/rotate-image
Submission Url: https://leetcode.com/problems/rotate-image/submissions/943203146
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int x = 0; x < n/2; x++) {

            for(int y = x; y < n-x-1; y++) {
                int temp = matrix[x][y];
                matrix[x][y] = matrix[n-y-1][x];
                matrix[n-y-1][x] = matrix[n-x-1][n-y-1];
                matrix[n-x-1][n-y-1] = matrix[y][n-x-1];
                matrix[y][n-x-1] = temp;
            }
        }
    }
};