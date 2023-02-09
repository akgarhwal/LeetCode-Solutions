/*
Problem Title: 45 - Jump Game II
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/jump-game-ii
Submission Url: https://leetcode.com/problems/jump-game-ii/submissions/893693642
*/

class Solution {
public:

    int solve(int index, vector<int>& nums, int count, vector<int>&  dp) {
        if(index >= nums.size()-1) {
            dp[nums.size()-1] = min(count, dp[nums.size()-1]);
            return count;
        }
        int ans = INT_MAX;
        for(int i =  min((int)nums.size()-1, (index + nums[index])); i > index; i--) {
            ans = min(ans, solve(i, nums, count+1, dp));
        }
        return dp[index] = ans;
    }

    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), INT_MAX);
        solve(0, nums, 0, dp);
        return dp[0];
    }
};