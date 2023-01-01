/* Question: Minimum Cost Homecoming of a Robot in a Grid
 * Lang: cpp
 * Runtime: 172 ms
 * Memory: 149.8 MB
 * Question Url:
 * https://leetcode.com/problems/minimum-cost-homecoming-of-a-robot-in-a-grid
 * Submission Url:
 * https://leetcode.com/problems/minimum-cost-homecoming-of-a-robot-in-a-grid/submissions/593481907
 */

class Solution {
public:
  int minCost(vector<int> &startPos, vector<int> &homePos,
              vector<int> &rowCosts, vector<int> &colCosts) {

    int ans = 0;
    if (startPos[0] < homePos[0]) {
      for (int i = startPos[0] + 1; i <= homePos[0]; i++) {
        ans += rowCosts[i];
      }
    } else {
      for (int i = startPos[0] - 1; i >= homePos[0]; i--) {
        ans += rowCosts[i];
      }
    }
    if (startPos[1] < homePos[1]) {
      for (int i = startPos[1] + 1; i <= homePos[1]; i++) {
        ans += colCosts[i];
      }
    } else {
      for (int i = startPos[1] - 1; i >= homePos[1]; i--) {
        ans += colCosts[i];
      }
    }
    return ans;
  }
};
