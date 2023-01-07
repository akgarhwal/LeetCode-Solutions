/* Question: Count Special Quadruplets
 * Lang: cpp
 * Runtime: 217 ms
 * Memory: 10.5 MB
 * Question Url: https://leetcode.com/problems/count-special-quadruplets
 * Submission Url:
 * https://leetcode.com/problems/count-special-quadruplets/submissions/549623292
 */

class Solution {
public:
  int countQuadruplets(vector<int> &nums) {
    int ans = 0, sz = nums.size();
    for (int i = 0; i < sz - 3; i++) {
      for (int j = i + 1; j < sz - 2; j++) {
        for (int k = j + 1; k < sz - 1; k++) {
          for (int l = k + 1; l < sz; l++) {

            if (nums[i] + nums[j] + nums[k] == nums[l]) {
              ans++;
            }
          }
        }
      }
    }
    return ans;
  }
};
