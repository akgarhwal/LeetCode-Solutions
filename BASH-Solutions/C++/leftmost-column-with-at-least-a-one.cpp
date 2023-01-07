/* Question: Leftmost Column with at Least a One
 * Lang: cpp
 * Runtime: 12 ms
 * Memory: 8.1 MB
 * Question Url:
 * https://leetcode.com/problems/leftmost-column-with-at-least-a-one Submission
 * Url:
 * https://leetcode.com/problems/leftmost-column-with-at-least-a-one/submissions/328173061
 */

/**
 * This is the BinaryMatrix's API interface.
 * You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
  int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
    vector<int> dim = binaryMatrix.dimensions();
    int n = dim[0], m = dim[1];

    int i = 0, j = m - 1;

    while (i < n && j >= 0) {
      if (binaryMatrix.get(i, j) == 1) {
        j--;
      } else {
        i++;
      }
    }
    if (j == m - 1) {
      j = -1;
    } else {
      j += 1;
    }
    return j;
  }
};
