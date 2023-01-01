/* Question: Trapping Rain Water
 * Lang: cpp
 * Runtime: 4 ms
 * Memory: 14.2 MB
 * Question Url: https://leetcode.com/problems/trapping-rain-water
 * Submission Url:
 * https://leetcode.com/problems/trapping-rain-water/submissions/504347061
 */

class Solution {
public:
  int trap(vector<int> &height) {
    if (height.size() == 0) {
      return 0;
    }
    vector<int> r_max(height.size(), -1);
    r_max[height.size() - 1] = height[height.size() - 1];
    for (int i = height.size() - 2; i >= 0; i--) {
      r_max[i] = max(r_max[i + 1], height[i]);
    }

    int l_max = -1;
    int ans = 0;
    for (int i = 0; i < height.size(); i++) {
      l_max = max(l_max, height[i]);
      int temp_ans = min(l_max, r_max[i]) - height[i];
      ans += temp_ans > 0 ? temp_ans : 0;
    }
    return ans;
  }
};
