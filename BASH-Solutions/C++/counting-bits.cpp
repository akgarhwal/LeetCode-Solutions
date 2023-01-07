/* Question: Counting Bits
 * Lang: cpp
 * Runtime: 4 ms
 * Memory: 7.8 MB
 * Question Url: https://leetcode.com/problems/counting-bits
 * Submission Url:
 * https://leetcode.com/problems/counting-bits/submissions/345761442
 */

class Solution {
public:
  vector<int> countBits(int num) {
    vector<int> res(num + 1);
    res[0] = 0;
    for (int index = 1; index <= num; index++) {
      res[index] = res[index & (index - 1)] + 1;
    }
    return res;
  }
};
