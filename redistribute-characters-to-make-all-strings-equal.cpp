/* Question: Redistribute Characters to Make All Strings Equal
 * Lang: cpp
 * Runtime: 20 ms
 * Memory: 12.2 MB
 * Question Url:
 * https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal
 * Submission Url:
 * https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/submissions/507079465
 */

class Solution {
public:
  bool makeEqual(vector<string> &words) {
    vector<int> dp(26, 0);
    for (string s : words) {
      for (char ch : s) {
        dp[ch - 'a']++;
      }
    }

    for (int x : dp) {
      if ((x % words.size()) != 0) {
        return false;
      }
    }
    return true;
  }
};
