/* Question: Subsets
 * Lang: cpp
 * Runtime: 8 ms
 * Memory: 8.5 MB
 * Question Url: https://leetcode.com/problems/subsets
 * Submission Url: https://leetcode.com/problems/subsets/submissions/309319911
 */

class Solution {
public:
  vector<vector<int>> subsets(vector<int> &nums) {

    vector<vector<int>> res;
    res.push_back(vector<int>());

    int i = 1, limit = pow(2, nums.size());

    while (i < limit) {

      int cur = i;
      vector<int> cs;
      int count = 0;
      while (cur > 0) {
        if ((cur & 1) == 1) {
          cs.push_back(nums[count]);
        }
        cur = cur >> 1;
        count++;
      }
      res.push_back(cs);
      i += 1;
    }
    return res;
  }
};
