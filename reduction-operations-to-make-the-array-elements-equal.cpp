/* Question: Reduction Operations to Make the Array Elements Equal
 * Lang: cpp
 * Runtime: 252 ms
 * Memory: 82.8 MB
 * Question Url:
 * https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal
 * Submission Url:
 * https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/submissions/503632441
 */

class Solution {
public:
  int reductionOperations(vector<int> &nums) {
    int ans = 0;
    sort(nums.begin(), nums.end());
    int st = nums[0], eqc = 0, cur = nums[0];
    for (int i = nums.size() - 1; i > 0; i--) {

      if (nums[i] == st) {
        break;
      }
      if (nums[i] == cur) {
        eqc++;
      } else {
        cur = nums[i];
        ans += eqc;
        eqc++;
      }
    }
    ans += (eqc);
    return ans;
  }
};
