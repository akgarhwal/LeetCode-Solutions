/* Question: Check if There is a Valid Partition For The Array
 * Lang: cpp
 * Runtime: 277 ms
 * Memory: 92.7 MB
 * Question Url:
 * https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array
 * Submission Url:
 * https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/submissions/767396609
 */

class Solution {
public:
  bool solve(int index, vector<int> &nums, vector<int> &dp) {
    bool res = false;

    if (index == nums.size()) {
      return true;
    }
    if (dp[index] != -1) {
      return dp[index];
    }
    if (index + 1 < nums.size() and nums[index] == nums[index + 1]) {
      res = res or solve(index + 2, nums, dp);
    }
    if (index + 2 < nums.size() and nums[index] == nums[index + 1] and
        nums[index + 1] == nums[index + 2]) {
      res = res or solve(index + 3, nums, dp);
    }
    if (index + 2 < nums.size() and nums[index] + 1 == nums[index + 1] and
        nums[index + 1] + 1 == nums[index + 2]) {
      res = res or solve(index + 3, nums, dp);
    }

    return dp[index] = res;
  }
  bool validPartition(vector<int> &nums) {
    vector<int> dp(nums.size(), -1);
    return solve(0, nums, dp);
  }
};
