/* Question: Search Insert Position
 * Lang: cpp
 * Runtime: 11 ms
 * Memory: 9.7 MB
 * Question Url: https://leetcode.com/problems/search-insert-position
 * Submission Url:
 * https://leetcode.com/problems/search-insert-position/submissions/592969467
 */

class Solution {
public:
  int searchInsert(vector<int> &nums, int target) {
    int start = 0, end = nums.size() - 1;

    while (start <= end) {

      int mid = (end - start) / 2 + start;

      if (nums[mid] == target) {
        return mid;
      }

      if (nums[mid] < target) {
        start += 1;
      } else {
        end -= 1;
      }
    }

    return start;
  }
};
