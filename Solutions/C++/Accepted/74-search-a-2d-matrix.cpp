/*
Problem Title: 74 - Search a 2D Matrix
Lang: C++
Runtime: 6 ms
Memory: 9.6 MB
Problem Url: https://leetcode.com/problems/search-a-2d-matrix
Submission Url: https://leetcode.com/problems/search-a-2d-matrix/submissions/890406372
*/

class Solution {
public:

    int findRow(vector<vector<int>>& matrix, int target) {
        int lo = 0, hi = matrix.size()-1;
        int lb = 0;
        while(lo <= hi) {
            int mid = lo + (hi-lo)/2;
            if(matrix[mid][0] > target) {
                hi = mid - 1;
            } else {
                lb = mid;
                lo = mid + 1;
            }
        }
        return lb;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = findRow(matrix, target);
        int lo = 0, hi = matrix[0].size()-1;

        while(lo <= hi) {
            int mid = lo + (hi-lo)/2;
            if(matrix[row][mid] == target) {
                return true;
            }
            if(matrix[row][mid] > target) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return false;
    }
};