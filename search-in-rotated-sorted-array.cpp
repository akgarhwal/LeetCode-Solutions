/* Question: Search in Rotated Sorted Array
 * Lang: cpp
 * Runtime: 8 ms
 * Memory: 6.5 MB
 * Question Url: https://leetcode.com/problems/search-in-rotated-sorted-array
 * Submission Url:
 * https://leetcode.com/problems/search-in-rotated-sorted-array/submissions/327052398
 */

class Solution {
public:
  int findMinIndex(vector<int> &nums, int lo, int hi) {
    if (hi <= lo)
      return lo;
    int mid = lo + (hi - lo) / 2;
    if (nums[mid] > nums[hi]) {
      return findMinIndex(nums, mid + 1, hi);
    }
    return findMinIndex(nums, lo, mid);
  }
  int search(vector<int> &nums, int target) {
    if (nums.size() == 0)
      return -1;
    int root = findMinIndex(nums, 0, nums.size() - 1);

    int lo = 0, hi = nums.size();

    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      int act_mid = (mid + root) % nums.size();
      if (nums[act_mid] == target)
        return act_mid;
      if (nums[act_mid] < target) {
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }
    return -1;
  }
};
