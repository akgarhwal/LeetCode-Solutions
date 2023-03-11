/*
Problem Title: 665 - Non-decreasing Array
Lang: C++
Runtime: 24 ms
Memory: 27 MB
Problem Url: https://leetcode.com/problems/non-decreasing-array
Submission Url: https://leetcode.com/problems/non-decreasing-array/submissions/912789167
*/

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool flag = false;
        
        for(int i = 0; i < (nums.size()-1); i++) {
            if( nums[i] <= nums[i+1]) {
                continue;
            }
            if(flag) {
                return false;
            }
            if( i == 0 || nums[i-1] <= nums[i+1]) {
                nums[i] = nums[i+1];
            } else {
                nums[i+1] = nums[i];
            }
            flag = true;
        }

        return true;
    }
};