/* Question: Running Sum of 1d Array
 * Lang: cpp
 * Runtime: 5 ms
 * Memory: 8.4 MB
 * Question Url: https://leetcode.com/problems/running-sum-of-1d-array
 * Submission Url:
 * https://leetcode.com/problems/running-sum-of-1d-array/submissions/763092296
 */

class Solution {
public:
  vector<int> runningSum(vector<int> &nums) {
    vector<int> sum;
    int rsum = 0;
    for (int num : nums) {
      rsum += num;
      sum.push_back(rsum);
    }
    return sum;
  }
};
