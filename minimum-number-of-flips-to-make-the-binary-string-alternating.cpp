/* Question: Minimum Number of Flips to Make the Binary String Alternating
 * Lang: cpp
 * Runtime: 84 ms
 * Memory: 25.1 MB
 * Question Url:
 * https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating
 * Submission Url:
 * https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/submissions/503695513
 */

class Solution {
public:
  int minFlips(string s) {
    int ans = INT_MAX;
    s += s;

    string s1 = "", s2 = "";
    for (int i = 0; i < s.size(); i++) {
      s1 += (i % 2) == 0 ? '0' : '1';
      s2 += (i % 2) == 0 ? '1' : '0';
    }
    int ans1 = 0, ans2 = 0;
    int n = s.size() / 2;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] != s1[i])
        ans1++;
      if (s[i] != s2[i])
        ans2++;

      if (i >= n) {
        if (s[i - n] != s1[i - n])
          ans1--;
        if (s[i - n] != s2[i - n])
          ans2--;
      }
      if (i >= n - 1)
        ans = min({ans1, ans2, ans});
    }
    return ans;
  }
};
