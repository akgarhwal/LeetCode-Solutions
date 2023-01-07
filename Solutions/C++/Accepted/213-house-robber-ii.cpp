/*
Problem Title: 213 - House Robber II
Lang: C++
Runtime: 0 ms
Memory: 8 MB
Problem Url: https://leetcode.com/problems/house-robber-ii
Submission Url: https://leetcode.com/problems/house-robber-ii/submissions/593400583
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        
        if(nums.size() == 1){
            return nums[0];
        }
        
        if(nums.size() == 2){
            return max(nums[0], nums[1]);
        }
        
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[1], nums[0]);
    
        for(int i=2;i<nums.size()-1;i++){
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        
        vector<int> dp2(nums.size());
        dp2[1] = nums[1];
        dp2[2] = max(nums[1], nums[2]);
    
        for(int i=3;i<nums.size();i++){
            dp2[i] = max(dp2[i-1], dp2[i-2] + nums[i]);
        }
        
        return max(dp[nums.size()-2], dp2[nums.size()-1]);
    }
};