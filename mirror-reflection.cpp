/* Question: Mirror Reflection
 * Lang: cpp
 * Runtime: 0 ms
 * Memory: 5.8 MB
 * Question Url: https://leetcode.com/problems/mirror-reflection
 * Submission Url:
 * https://leetcode.com/problems/mirror-reflection/submissions/764877568
 */

class Solution {
public:
  int mirrorReflection(int p, int q) {
    int px = 2;
    int qx = 1;

    while (true) {
      if ((q * qx) % p == 0) {
        return ((q * qx) / p) % 2;
      }
      qx += 2;

      if ((q * px) % p == 0) {
        return 2;
      }
      px += 2;
    }
    return 0;
  }
};
