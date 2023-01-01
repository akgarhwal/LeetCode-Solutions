/* Question: Excel Sheet Column Title
 * Lang: cpp
 * Runtime: 0 ms
 * Memory: 7.1 MB
 * Question Url: https://leetcode.com/problems/excel-sheet-column-title
 * Submission Url:
 * https://leetcode.com/problems/excel-sheet-column-title/submissions/309754036
 */

class Solution {
public:
  string convertToTitle(int n) {
    string ans = "";
    while (n > 0) {
      ans = char(((n - 1) % 26) + 'A') + ans;
      n = (n - 1) / 26;
    }
    return ans;
  }
};
