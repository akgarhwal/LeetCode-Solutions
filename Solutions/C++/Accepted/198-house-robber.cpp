/*
Problem Title: 198 - House Robber
Lang: C++
Runtime: 4 ms
Memory: 7.9 MB
Problem Url: https://leetcode.com/problems/house-robber
Submission Url: https://leetcode.com/problems/house-robber/submissions/595189289
*/

class Solution {
public:
    int rob(vector<int>& nums) {

        if(nums.size() == 1){
            return nums[0];
        }


        vector<vector<int>> dp(2);

        dp[0].push_back(0);
        dp[1].push_back(nums[0]); 

        for(int i = 1; i < nums.size(); i++){

            dp[0].push_back(max(dp[1][i-1], dp[0][i-1]));
            dp[1].push_back(dp[0][i-1] + nums[i]);

        }

        return max(dp[0][nums.size()-1], dp[1][nums.size()-1]);
    }
};