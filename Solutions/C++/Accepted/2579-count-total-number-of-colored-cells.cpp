/*
Problem Title: 2579 - Count Total Number of Colored Cells
Lang: C++
Runtime: 7 ms
Memory: 6 MB
Problem Url: https://leetcode.com/problems/count-total-number-of-colored-cells
Submission Url: https://leetcode.com/problems/count-total-number-of-colored-cells/submissions/909205184
*/

class Solution {
public:
    long long coloredCells(int n) {
        long long ans = 1, factor = 4;

        for(int i = 2; i <= n ; i++){
            ans = ans + factor;
            factor += 4;
        }

        return ans;
    }
};