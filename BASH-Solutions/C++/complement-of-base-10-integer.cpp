/* Question: Complement of Base 10 Integer
 * Lang: cpp
 * Runtime: 4 ms
 * Memory: 5.8 MB
 * Question Url: https://leetcode.com/problems/complement-of-base-10-integer
 * Submission Url:
 * https://leetcode.com/problems/complement-of-base-10-integer/submissions/612626901
 */

class Solution {
public:
  int bitwiseComplement(int n) {
    if (n == 0) {
      return 1;
    }
    int ans = 0, i = 0;
    while (n) {
      int bit = n & 1;
      if (!bit) {
        ans = ans | (1 << i);
      }
      i++;
      n = n >> 1;
    }
    return ans;
  }
};
