/*
Problem Title: 1696 - Jump Game VI
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/jump-game-vi
Submission Url: https://leetcode.com/problems/jump-game-vi/submissions/505321168
*/

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        unordered_map<int,int> dp;
        return fun(0, nums, k, dp);
    }
    int fun(int ind, vector<int> &nums, int k, unordered_map<int,int> &dp){
        if(ind >= nums.size()){
            return 0;
        }
        if(dp.find(ind) != dp.end()){
            return dp[ind];
        }
        int ans = INT_MIN;
        for(int i=ind; i < min((int)nums.size(), ind+k); i++){
            ans = max(ans, fun(i+1, nums, k, dp)+ nums[i]);
        }
        return dp[ind] = ans;
    }
};