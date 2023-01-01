/* Question: Unique Morse Code Words
 * Lang: cpp
 * Runtime: 3 ms
 * Memory: 8.6 MB
 * Question Url: https://leetcode.com/problems/unique-morse-code-words
 * Submission Url:
 * https://leetcode.com/problems/unique-morse-code-words/submissions/775706250
 */

class Solution {
public:
  int uniqueMorseRepresentations(vector<string> &words) {
    vector<string> dict{".-",   "-...", "-.-.", "-..",  ".",    "..-.", "--.",
                        "....", "..",   ".---", "-.-",  ".-..", "--",   "-.",
                        "---",  ".--.", "--.-", ".-.",  "...",  "-",    "..-",
                        "...-", ".--",  "-..-", "-.--", "--.."};

    set<string> st;
    for (string word : words) {

      string trans = "";

      for (char ch : word) {
        trans += dict[ch - 'a'];
      }

      st.insert(trans);
    }

    return st.size();
  }
};
