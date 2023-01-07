/* Question: Hamming Distance
 * Lang: cpp
 * Runtime: 0 ms
 * Memory: 5.9 MB
 * Question Url: https://leetcode.com/problems/hamming-distance
 * Submission Url:
 * https://leetcode.com/problems/hamming-distance/submissions/362515280
 */

class Solution {
public:
  int hammingDistance(int x, int y) {
    int xo = x ^ y;
    int ans = 0;
    while (xo > 0) {
      if ((xo & 1) > 0) {
        ans++;
      }
      xo = xo >> 1;
    }
    return ans;
  }
};
