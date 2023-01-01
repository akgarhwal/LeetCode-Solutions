/* Question: Longest Palindromic Substring
 * Lang: cpp
 * Runtime: 195 ms
 * Memory: 163.8 MB
 * Question Url: https://leetcode.com/problems/longest-palindromic-substring
 * Submission Url:
 * https://leetcode.com/problems/longest-palindromic-substring/submissions/766092153
 */

class Solution {
public:
  int findMaxLength(string s, int left, int right) {
    while (left >= 0 and right < s.size() and s[left] == s[right]) {
      left--;
      right++;
    }
    return right - left - 1;
  }

  string longestPalindrome(string s) {

    int maxLen = 0, left = -1, right = -1, temp = 0;
    string ans = s.substr(0, 1);

    for (int i = 0; i < s.size() - 1; i++) {

      temp = findMaxLength(s, i, i);
      if (temp > maxLen) {
        maxLen = temp;
        ans = s.substr(i - temp / 2, temp);
      }

      temp = findMaxLength(s, i, i + 1);
      if (temp > maxLen) {
        maxLen = temp;
        ans = s.substr(i - temp / 2 + 1, temp);
      }
    }

    return ans;
  }
};
