/*
Problem Title: 53 - Maximum Subarray
Lang: C++
Runtime: 104 ms
Memory: 67.8 MB
Problem Url: https://leetcode.com/problems/maximum-subarray
Submission Url: https://leetcode.com/problems/maximum-subarray/submissions/594217533
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0], sum = nums[0];
        for(int i =1; i < nums.size(); i++) {
            if(sum < 0){
                sum = 0;
            }
            sum += nums[i];
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};