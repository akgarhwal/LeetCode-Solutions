/*
Problem Title: 2529 - Maximum Count of Positive Integer and Negative Integer
Lang: C++
Runtime: 20 ms
Memory: 17.5 MB
Problem Url: https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer
Submission Url: https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/submissions/873703842
*/

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int nc = 0, pc = 0;
        for(int num : nums){
            nc += (num < 0 ? 1 : 0);
            pc += (num > 0 ? 1 : 0);
        }
        return max(nc, pc);
    }
};