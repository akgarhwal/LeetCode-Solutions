/*
Problem Title: 1920 - Build Array from Permutation
Lang: C++
Runtime: 13 ms
Memory: 16.3 MB
Problem Url: https://leetcode.com/problems/build-array-from-permutation
Submission Url: https://leetcode.com/problems/build-array-from-permutation/submissions/873464751
*/

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        for(int i=0; i < nums.size(); i++) {
            ans[i] = nums[nums[i]];
        }
        return ans;
    }
};