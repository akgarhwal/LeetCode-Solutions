/* Question: Longest Palindrome
 * Lang: cpp
 * Runtime: 4 ms
 * Memory: 6.7 MB
 * Question Url: https://leetcode.com/problems/longest-palindrome
 * Submission Url:
 * https://leetcode.com/problems/longest-palindrome/submissions/766307050
 */

class Solution {
public:
  int longestPalindrome(string s) {

    unordered_map<char, int> mp;

    for (char ch : s) {
      mp[ch] += 1;
    }

    int ans = 0;
    bool isOdd = false;

    for (auto pi : mp) {

      if (pi.second % 2 == 1) {
        isOdd = true;
        ans += pi.second - 1;
      } else {
        ans += pi.second;
      }
    }

    return ans + isOdd;
  }
};
