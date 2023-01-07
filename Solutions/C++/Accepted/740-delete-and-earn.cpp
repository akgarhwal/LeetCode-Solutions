/*
Problem Title: 740 - Delete and Earn
Lang: C++
Runtime: 12 ms
Memory: 13.8 MB
Problem Url: https://leetcode.com/problems/delete-and-earn
Submission Url: https://leetcode.com/problems/delete-and-earn/submissions/593414268
*/

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        vector<int> data(10001, 0);
        vector<int> dp(10001, 0);
        for(int x : nums){
            data[x]++;
        }
        dp[1] = data[1];
        for(int i = 2; i<= 10000; i++){
            dp[i]= max(dp[i-1], dp[i-2] + data[i] * i);
        }
        return dp[10000];
    }
};