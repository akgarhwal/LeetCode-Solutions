/*
Problem Title: 1523 - Count Odd Numbers in an Interval Range
Lang: C++
Runtime: 3 ms
Memory: 6.1 MB
Problem Url: https://leetcode.com/problems/count-odd-numbers-in-an-interval-range
Submission Url: https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/submissions/896840129
*/

class Solution {
public:
    int countOdds(int low, int high) {
        return ceil(high/2.0) - floor(low/2.0);
    }
};