/*
Problem Title: 45 - Jump Game II
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/jump-game-ii
Submission Url: https://leetcode.com/problems/jump-game-ii/submissions/893687146
*/

class Solution {
public:

    int solve(int index, vector<int>& nums, int count, vector<int>& dp) {
        if(index >= nums.size()-1) {
            return count;
        }
        if(dp[index] != INT_MAX) {
            return dp[index];
        }
        int ans = INT_MAX;
        for(int i = index + nums[index]; i > index; i--) {
            ans = min(ans, solve(i, nums, count+1, dp));
        }
        return dp[index] = ans;
    }

    int jump(vector<int>& nums) {
        int ans = INT_MAX;
        vector<int> dp(nums.size(), INT_MAX);
        ans = solve(0, nums, 0, dp);
        return ans;
    }
};

