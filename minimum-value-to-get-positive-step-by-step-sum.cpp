/* Question: Minimum Value to Get Positive Step by Step Sum
 * Lang: cpp
 * Runtime: 0 ms
 * Memory: 7.4 MB
 * Question Url:
 * https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum
 * Submission Url:
 * https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum/submissions/326593925
 */

class Solution {
public:
  int minStartValue(vector<int> &nums) {
    int sum = 0, mi = INT_MAX;
    for (int x : nums) {
      sum += x;
      mi = min(mi, sum);
    }

    return max(1, -1 * mi + 1);
  }
};
