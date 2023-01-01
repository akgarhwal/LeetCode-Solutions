/* Question: How Many Numbers Are Smaller Than the Current Number
 * Lang: cpp
 * Runtime: 32 ms
 * Memory: 7.9 MB
 * Question Url:
 * https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number
 * Submission Url:
 * https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/submissions/308130409
 */

class Solution {
public:
  vector<int> smallerNumbersThanCurrent(vector<int> &nums) {

    vector<int> ans(nums.size(), 0);

    for (int i = 0; i < nums.size(); i++) {

      int count = 0;

      for (int j = 0; j < nums.size(); j++) {

        if (j != i && nums[j] < nums[i]) {
          count++;
        }
      }
      ans[i] = count;
    }
    return ans;
  }
};
