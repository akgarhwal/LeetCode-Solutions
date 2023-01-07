/* Question: Determine Color of a Chessboard Square
 * Lang: cpp
 * Runtime: 0 ms
 * Memory: 5.7 MB
 * Question Url:
 * https://leetcode.com/problems/determine-color-of-a-chessboard-square
 * Submission Url:
 * https://leetcode.com/problems/determine-color-of-a-chessboard-square/submissions/475914630
 */

class Solution {
public:
  bool squareIsWhite(string coordinates) {
    int first = coordinates[0] - 'a';
    int second = coordinates[1] - '0';

    if (first % 2 == 0 and second % 2 == 0) {
      return true;
    }
    if (first % 2 == 1 and second % 2 == 1) {
      return true;
    }
    return false;
  }
};
