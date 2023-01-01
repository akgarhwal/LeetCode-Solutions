/* Question: Number of Arithmetic Triplets
 * Lang: cpp
 * Runtime: 1828 ms
 * Memory: 8.5 MB
 * Question Url: https://leetcode.com/problems/number-of-arithmetic-triplets
 * Submission Url:
 * https://leetcode.com/problems/number-of-arithmetic-triplets/submissions/767348290
 */

class Solution {
public:
  int arithmeticTriplets(vector<int> &nums, int diff) {
    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {

      for (int j = 1; j < nums.size(); j++) {

        for (int k = 2; k < nums.size(); k++) {
          if (nums[j] - nums[i] == diff and nums[k] - nums[j] == diff) {
            ans++;
          }
        }
      }
    }
    return ans;
  }
};
