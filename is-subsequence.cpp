/* Question: Is Subsequence
 * Lang: cpp
 * Runtime: 3 ms
 * Memory: 6.2 MB
 * Question Url: https://leetcode.com/problems/is-subsequence
 * Submission Url:
 * https://leetcode.com/problems/is-subsequence/submissions/763884139
 */

class Solution {
public:
  bool isSubsequence(string s, string t) {
    int index_s = 0, index_t = 0;
    for (; index_t < t.size(); index_t++) {
      if (s[index_s] == t[index_t]) {
        index_s++;
      }
    }
    return index_s == s.size();
  }
};
