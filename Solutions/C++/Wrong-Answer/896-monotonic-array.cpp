/*
Problem Title: 896 - Monotonic Array
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/monotonic-array
Submission Url: https://leetcode.com/problems/monotonic-array/submissions/940125079
*/

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool isIncreasing = true, isDecreasing = true;

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i-1] > nums[i]){
                isIncreasing = false;
                break;
            }
            if(nums[i-1] < nums[i]){
                isDecreasing = false;
                break;
            }
        }

        return isIncreasing or isDecreasing;
    }
};