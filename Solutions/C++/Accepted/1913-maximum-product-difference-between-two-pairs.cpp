/*
Problem Title: 1913 - Maximum Product Difference Between Two Pairs
Lang: C++
Runtime: 48 ms
Memory: 20.4 MB
Problem Url: https://leetcode.com/problems/maximum-product-difference-between-two-pairs
Submission Url: https://leetcode.com/problems/maximum-product-difference-between-two-pairs/submissions/513707275
*/

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int N = nums.size();
        return ((nums[N-1]*nums[N-2]) - (nums[0]*nums[1]));
    }
};