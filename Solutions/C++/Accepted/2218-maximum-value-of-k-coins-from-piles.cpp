/*
Problem Title: 2218 - Maximum Value of K Coins From Piles
Lang: C++
Runtime: 272 ms
Memory: 18.1 MB
Problem Url: https://leetcode.com/problems/maximum-value-of-k-coins-from-piles
Submission Url: https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/submissions/933919206
*/

class Solution {
public:

    int solve(vector<vector<int>>& A, int k, int i, vector<vector<int>>& dp) {
        if (dp[i][k] > 0) {
            return dp[i][k];
        }
        if (i == A.size() || k == 0) {
            return 0;
        }

        int res = solve(A, k, i+1, dp), cur = 0;

        for (int j = 0; j < A[i].size() && j < k; ++j) {
            cur += A[i][j];
            res = max(res, solve(A, k-j-1, i + 1, dp) + cur);
        }

        return dp[i][k] = res;
    }


    int maxValueOfCoins(vector<vector<int>>& A, int K) {
        int n = A.size();
        vector<vector<int>> dp(n + 1, vector<int>(K + 1, 0));

        return solve(A, K, 0, dp);
    }
};