/* Question: Find Target Indices After Sorting Array
 * Lang: cpp
 * Runtime: 4 ms
 * Memory: 11.6 MB
 * Question Url:
 * https://leetcode.com/problems/find-target-indices-after-sorting-array
 * Submission Url:
 * https://leetcode.com/problems/find-target-indices-after-sorting-array/submissions/596712040
 */

class Solution {
public:
  vector<int> targetIndices(vector<int> &nums, int target) {
    // sort(nums.begin(), nums.end());
    vector<int> ans;
    int less = 0, eq = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == target) {
        eq++;
      }
      if (nums[i] < target) {
        less++;
      }
    }
    while (eq--) {
      ans.push_back(less++);
    }
    return ans;
  }
};
