/*
Problem Title: 2466 - Count Ways To Build Good Strings
Lang: C++
Runtime: 12 ms
Memory: 12.4 MB
Problem Url: https://leetcode.com/problems/count-ways-to-build-good-strings
Submission Url: https://leetcode.com/problems/count-ways-to-build-good-strings/submissions/949382667
*/

class Solution {
public:

    int dfs(int length, int zero, int one, vector<int>& dp) {
        if (dp[length] != -1) {
            return dp[length];
        }
        int count = 0;

        if (length >= one) {
            count += dfs(length - one, zero, one, dp);
        }
        if (length >= zero) {
            count += dfs(length - zero, zero, one, dp);
        }

        return dp[length] = count % int(1e9+7);
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, -1);
        dp[0] = 1;
        
        int answer = 0;
        for (int length = low; length <= high; length++) {
            answer += dfs(length, zero, one, dp);
            answer %= int(1e9+7);
        }
        return answer;
    }
};