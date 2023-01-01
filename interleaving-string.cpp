/* Question: Interleaving String
 * Lang: cpp
 * Runtime: 16 ms
 * Memory: 11.7 MB
 * Question Url: https://leetcode.com/problems/interleaving-string
 * Submission Url:
 * https://leetcode.com/problems/interleaving-string/submissions/501811787
 */

class Solution {
public:
  bool isValid(string &s1, string &s2, string &s3, int i, int j, int k,
               vector<vector<int>> &dp) {
    if (k == s3.size()) {
      return true;
    }
    if (dp[i][j] != -1) {
      return dp[i][j];
    }

    bool res = true;
    if (s1[i] == s2[j] and s1[i] == s3[k]) {
      bool temp = isValid(s1, s2, s3, i + 1, j, k + 1, dp);
      if (!temp) {
        res = res and isValid(s1, s2, s3, i, j + 1, k + 1, dp);
      }
    } else if (s1[i] == s3[k]) {
      res = res and isValid(s1, s2, s3, i + 1, j, k + 1, dp);
    } else if (s2[j] == s3[k]) {
      res = res and isValid(s1, s2, s3, i, j + 1, k + 1, dp);
    } else {
      res = false;
    }
    return dp[i][j] = res;
  }
  bool isInterleave(string s1, string s2, string s3) {
    if (s1.size() + s2.size() != s3.size()) {
      return false;
    }
    vector<vector<int>> dp(100, vector<int>(100, -1));
    return isValid(s1, s2, s3, 0, 0, 0, dp);
  }
};
