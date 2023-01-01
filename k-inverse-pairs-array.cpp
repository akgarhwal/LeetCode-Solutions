/* Question: K Inverse Pairs Array
 * Lang: cpp
 * Runtime: 71 ms
 * Memory: 16.4 MB
 * Question Url: https://leetcode.com/problems/k-inverse-pairs-array
 * Submission Url:
 * https://leetcode.com/problems/k-inverse-pairs-array/submissions/749327645
 */

class Solution {
public:
  int kInversePairs(int n, int k) {
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    int M = 1000000007;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= k; j++) {
        if (j == 0)
          dp[i][j] = 1;
        else {
          int val =
              (dp[i - 1][j] + M - ((j - i) >= 0 ? dp[i - 1][j - i] : 0)) % M;
          dp[i][j] = (dp[i][j - 1] + val) % M;
        }
      }
    }
    return ((dp[n][k] + M - (k > 0 ? dp[n][k - 1] : 0)) % M);
    ;
  }
};
