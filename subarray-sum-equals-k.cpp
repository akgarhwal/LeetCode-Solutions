/* Question: Subarray Sum Equals K
 * Lang: cpp
 * Runtime: 44 ms
 * Memory: 15.3 MB
 * Question Url: https://leetcode.com/problems/subarray-sum-equals-k
 * Submission Url:
 * https://leetcode.com/problems/subarray-sum-equals-k/submissions/328508283
 */

class Solution {
public:
  int subarraySum(vector<int> &nums, int k) {
    unordered_map<int, int> mp;
    int ans = 0, sum = 0;
    mp[0] = 1;
    for (int num : nums) {
      sum += num;
      ans += mp[sum - k];
      mp[sum] += 1;
    }
    return ans;
  }
};
