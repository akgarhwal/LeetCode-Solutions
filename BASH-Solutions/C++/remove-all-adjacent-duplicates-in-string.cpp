/* Question: Remove All Adjacent Duplicates In String
 * Lang: cpp
 * Runtime: 12 ms
 * Memory: 10.1 MB
 * Question Url:
 * https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string
 * Submission Url:
 * https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/submissions/514777904
 */

class Solution {
public:
  string removeDuplicates(string S) {
    string ans;
    for (char i : S) {
      if (ans.size() == 0)
        ans.push_back(i);
      else if (i == ans.back())
        ans.pop_back();
      else
        ans.push_back(i);
    }
    return ans;
  }
};
