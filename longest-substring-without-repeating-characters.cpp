/* Question: Longest Substring Without Repeating Characters
 * Lang: cpp
 * Runtime: 98 ms
 * Memory: 13.3 MB
 * Question Url:
 * https://leetcode.com/problems/longest-substring-without-repeating-characters
 * Submission Url:
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/766076263
 */

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int ans = 0;
    int first = 0, second = 0;
    set<char> st;

    while (first < s.size()) {

      while (second < s.size()) {
        if (st.find(s[second]) != st.end()) {
          break;
        }
        st.insert(s[second++]);
        ans = max(ans, second - first);
      }
      st.erase(s[first++]);
    }

    return ans;
  }
};
