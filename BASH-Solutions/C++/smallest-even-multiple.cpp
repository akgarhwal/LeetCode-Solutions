/* Question: Smallest Even Multiple
 * Lang: cpp
 * Runtime: 0 ms
 * Memory: 6 MB
 * Question Url: https://leetcode.com/problems/smallest-even-multiple
 * Submission Url:
 * https://leetcode.com/problems/smallest-even-multiple/submissions/868363812
 */

class Solution {
public:
  int smallestEvenMultiple(int n) { return (n & 1) > 0 ? n << 1 : n; }
};
