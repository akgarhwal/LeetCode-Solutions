/*
Problem Title: 912 - Sort an Array
Lang: C++
Runtime: 126 ms
Memory: 61.3 MB
Problem Url: https://leetcode.com/problems/sort-an-array
Submission Url: https://leetcode.com/problems/sort-an-array/submissions/907218976
*/

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums;
    }
};