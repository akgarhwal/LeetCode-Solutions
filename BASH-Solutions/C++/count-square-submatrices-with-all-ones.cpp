/* Question: Count Square Submatrices with All Ones
 * Lang: cpp
 * Runtime: 156 ms
 * Memory: 23.7 MB
 * Question Url:
 * https://leetcode.com/problems/count-square-submatrices-with-all-ones
 * Submission Url:
 * https://leetcode.com/problems/count-square-submatrices-with-all-ones/submissions/342567448
 */

class Solution {
public:
  int countSquares(vector<vector<int>> &matrix) {
    unordered_map<int, int> mp;
    int ans = 0;
    for (int i = 0; i < matrix.size(); i++) {
      ans += matrix[i][0];
    }
    for (int i = 1; i < matrix[0].size(); i++) {
      ans += matrix[0][i];
    }
    for (int i = 1; i < matrix.size(); i++) {
      for (int j = 1; j < matrix[0].size(); j++) {

        ans += matrix[i][j];
        if (matrix[i][j] == 1) {

          int mi =
              min({matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]});
          matrix[i][j] = mi + 1;
          if (mi > 0)
            ans += (mi);
        }
      }
    }

    return ans;
  }
};
