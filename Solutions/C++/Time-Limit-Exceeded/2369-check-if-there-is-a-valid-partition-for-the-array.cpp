/*
Problem Title: 2369 - Check if There is a Valid Partition For The Array
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array
Submission Url: https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/submissions/767395271
*/

class Solution {
public:
    bool solve(int index, vector<int> &nums) {
        bool res = false;
        
        if(index == nums.size()){
            return true;
        }
        if(index + 1 < nums.size() and nums[index] == nums[index+1]) {
            res = res or solve(index+2, nums);
        } 
        if(index + 2 < nums.size() and nums[index] == nums[index + 1] and nums[index + 1] == nums[index + 2]) {
            res = res or solve(index+3, nums);
        } 
        if(index + 2 < nums.size() and nums[index]+1 == nums[index + 1] and nums[index + 1] + 1 == nums[index + 2]) {
            res = res or solve(index+3, nums);
        }
        
        return res;
    }
    bool validPartition(vector<int>& nums) {
        return solve(0, nums);
    }
};