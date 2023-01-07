/* Question: Jump Game II
 * Lang: cpp
 * Runtime: 21 ms
 * Memory: 16.3 MB
 * Question Url: https://leetcode.com/problems/jump-game-ii
 * Submission Url:
 * https://leetcode.com/problems/jump-game-ii/submissions/593765044
 */

class Solution {
public:
  int jump(vector<int> &nums) {
    for (int i = 0; i < nums.size(); i++) {
      nums[i] = nums[i] + i;
    }
    int ans = 0, i = 1, mx = nums[0];
    while (i < nums.size()) {
      int j = mx;
      while (i <= j and i < nums.size()) {
        mx = max(mx, nums[i]);
        i++;
      }
      ans++;
    }
    return ans;
  }
};
