/* Question: First Letter to Appear Twice
 * Lang: cpp
 * Runtime: 4 ms
 * Memory: 6.2 MB
 * Question Url: https://leetcode.com/problems/first-letter-to-appear-twice
 * Submission Url:
 * https://leetcode.com/problems/first-letter-to-appear-twice/submissions/765043609
 */

class Solution {
public:
  char repeatedCharacter(string s) {
    set<char> st;
    for (char ch : s) {
      if (st.find(ch) != st.end()) {
        return ch;
      }
      st.insert(ch);
    }
    return ' ';
  }
};
