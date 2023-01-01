/* Question: Combination Sum IV
 * Lang: cpp
 * Runtime: 6 ms
 * Memory: 6.6 MB
 * Question Url: https://leetcode.com/problems/combination-sum-iv
 * Submission Url:
 * https://leetcode.com/problems/combination-sum-iv/submissions/766062328
 */

class Solution {
public:
  int solve(vector<int> &nums, int target, vector<int> &dp) {

    if (dp[target] != -1) {
      return dp[target];
    }
    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (target >= nums[i]) {
        ans += solve(nums, target - nums[i], dp);
      }
    }
    return dp[target] = ans;
  }

  int combinationSum4(vector<int> &nums, int target) {

    vector<int> dp(target + 1, -1);
    dp[0] = 1;

    return solve(nums, target, dp);
  }
};
