/* Question: Maximum Alternating Subsequence Sum
 * Lang: cpp
 * Runtime: 168 ms
 * Memory: 91 MB
 * Question Url:
 * https://leetcode.com/problems/maximum-alternating-subsequence-sum Submission
 * Url:
 * https://leetcode.com/problems/maximum-alternating-subsequence-sum/submissions/513759234
 */

class Solution {
public:
  long long maxAlternatingSum(vector<int> &nums) {

    long ans = nums[0];
    bool peak = true;

    long se = 0, so = 0;
    int i = 1, N = nums.size();
    while (i < N) {

      if (peak) {
        while (i < N and nums[i] >= nums[i - 1]) {
          i++;
        }
        se += nums[i - 1];
      } else {
        while (i < N and nums[i - 1] >= nums[i]) {
          i++;
        }
        so += nums[i - 1];
      }
      ans = max(ans, se - so);
      peak = !peak;
    }

    return ans;
  }
};
