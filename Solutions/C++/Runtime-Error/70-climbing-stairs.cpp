/*
Problem Title: 70 - Climbing Stairs
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/climbing-stairs
Submission Url: https://leetcode.com/problems/climbing-stairs/submissions/772314548
*/

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};