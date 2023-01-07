/* Question: Remove One Element to Make the Array Strictly Increasing
 * Lang: cpp
 * Runtime: 88 ms
 * Memory: 9.9 MB
 * Question Url:
 * https://leetcode.com/problems/remove-one-element-to-make-the-array-strictly-increasing
 * Submission Url:
 * https://leetcode.com/problems/remove-one-element-to-make-the-array-strictly-increasing/submissions/513755338
 */

class Solution {
public:
  bool canBeIncreasing(vector<int> &nums) {
    int count = 0, li = 0;
    for (int i = 0; i < nums.size(); i++) {
      bool res = true;
      for (int j = 0; j < nums.size(); j++) {
        if (j == i) {
          continue;
        }
        if (j - 1 == i and j - 1 > 0 and nums[j] <= nums[j - 2]) {
          res = false;
          break;
        } else if (j - 1 == i and j - 1 == 0) {
          continue;
        } else if (j != 0 and j - 1 != i and nums[j] <= nums[j - 1]) {
          res = false;
          break;
        }
      }
      if (res) {
        return true;
      }
    }
    return false;
  }
};
