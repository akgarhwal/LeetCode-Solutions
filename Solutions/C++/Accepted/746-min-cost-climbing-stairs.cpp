/*
Problem Title: 746 - Min Cost Climbing Stairs
Lang: C++
Runtime: 4 ms
Memory: 13.8 MB
Problem Url: https://leetcode.com/problems/min-cost-climbing-stairs
Submission Url: https://leetcode.com/problems/min-cost-climbing-stairs/submissions/772315448
*/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(), 0);
        
        dp[0] = cost[0];
        dp[1] = cost[1];
        
        for(int i=2;i<cost.size();i++){
            dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
        }
        return min(dp[cost.size()-1],dp[cost.size()-2]);
    }
};