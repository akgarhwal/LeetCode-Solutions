/* Question: Simplified Fractions
 * Lang: cpp
 * Runtime: 244 ms
 * Memory: 21.8 MB
 * Question Url: https://leetcode.com/problems/simplified-fractions
 * Submission Url:
 * https://leetcode.com/problems/simplified-fractions/submissions/340178500
 */

class Solution {
public:
  vector<string> simplifiedFractions(int n) {
    vector<string> ans;
    for (int i = 1; i < n; i++) {
      for (int j = i + 1; j <= n; j++) {

        int n = i;
        int d = j;

        if (__gcd(n, d) == 1) {
          ans.push_back(to_string(n) + "/" + to_string(d));
        }
      }
    }
    return ans;
  }
};
