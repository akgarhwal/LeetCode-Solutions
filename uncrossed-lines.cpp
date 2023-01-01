/* Question: Uncrossed Lines
 * Lang: cpp
 * Runtime: 28 ms
 * Memory: 13 MB
 * Question Url: https://leetcode.com/problems/uncrossed-lines
 * Submission Url:
 * https://leetcode.com/problems/uncrossed-lines/submissions/344529424
 */

class Solution {
public:
  int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2) {
    int r = nums1.size(), c = nums2.size();
    vector<vector<int>> mat(r, vector<int>(c, 0));
    int mx = INT_MIN;
    mat[0][0] = int(nums1[0] == nums2[0]);
    for (int i = 1; i < c; i++) {

      mat[0][i] = max(mat[0][i - 1], int(nums2[i] == nums1[0]));
    }
    for (int i = 1; i < r; i++) {

      mat[i][0] = max(mat[i - 1][0], int(nums1[i] == nums2[0]));
    }

    for (int i = 1; i < r; i++) {
      for (int j = 1; j < c; j++) {

        int t1 = int(nums1[i] == nums2[j]) + mat[i - 1][j - 1];

        mat[i][j] = max({t1, mat[i][j - 1], mat[i - 1][j]});
      }
    }

    return mat[r - 1][c - 1];
  }
};
