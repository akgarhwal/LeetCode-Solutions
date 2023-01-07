/* Question: Majority Element
 * Lang: cpp
 * Runtime: 44 ms
 * Memory: 19.7 MB
 * Question Url: https://leetcode.com/problems/majority-element
 * Submission Url:
 * https://leetcode.com/problems/majority-element/submissions/335168190
 */

class Solution {
public:
  int majorityElement(vector<int> &nums) {
    int ans = 0, count = 0;
    for (int num : nums) {
      if (count == 0) {
        ans = num;
      }
      if (num == ans) {
        count++;
      } else {
        count--;
      }
    }
    return ans;
  }
};
