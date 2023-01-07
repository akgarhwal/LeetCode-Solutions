/*
Problem Title: 53 - Maximum Subarray
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/maximum-subarray
Submission Url: https://leetcode.com/problems/maximum-subarray/submissions/594217440
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0], sum = nums[0];
        for(int i =0; i < nums.size(); i++) {
            if(sum < 0){
                sum = 0;
            }
            sum += nums[i];
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};