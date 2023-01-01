/* Question: String Matching in an Array
 * Lang: cpp
 * Runtime: 28 ms
 * Memory: 9.1 MB
 * Question Url: https://leetcode.com/problems/string-matching-in-an-array
 * Submission Url:
 * https://leetcode.com/problems/string-matching-in-an-array/submissions/323543066
 */

class Solution {
public:
  bool isSubString(string word, vector<string> &words) {
    for (string str : words) {
      if (str == word) {
        continue;
      }
      if (str.find(word) != string::npos) {
        return true;
      }
    }
    return false;
  }

  vector<string> stringMatching(vector<string> &words) {
    vector<string> ans;
    for (string word : words) {
      if (isSubString(word, words)) {
        ans.push_back(word);
      }
    }
    return ans;
  }
};
