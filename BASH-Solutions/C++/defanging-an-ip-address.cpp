/* Question: Defanging an IP Address
 * Lang: cpp
 * Runtime: 0 ms
 * Memory: 6 MB
 * Question Url: https://leetcode.com/problems/defanging-an-ip-address
 * Submission Url:
 * https://leetcode.com/problems/defanging-an-ip-address/submissions/849151424
 */

class Solution {
public:
  string defangIPaddr(string address) {
    string ans = "";
    for (char ch : address) {
      if (ch == '.') {
        ans += "[.]";
      } else {
        ans += ch;
      }
    }
    return ans;
  }
};
