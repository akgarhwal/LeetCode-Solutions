/* Question: Permutations
 * Lang: cpp
 * Runtime: 8 ms
 * Memory: 8.6 MB
 * Question Url: https://leetcode.com/problems/permutations
 * Submission Url:
 * https://leetcode.com/problems/permutations/submissions/310134066
 */

class Solution {
public:
  void helper(vector<int> &nums, int pos, vector<vector<int>> &ans) {

    if (pos == nums.size()) {
      ans.push_back(nums);
      return;
    }

    for (int i = pos; i < nums.size(); i++) {
      swap(nums[i], nums[pos]);
      helper(nums, pos + 1, ans);
      swap(nums[i], nums[pos]);
    }
  }
  vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> ans;
    helper(nums, 0, ans);
    return ans;
  }
};
