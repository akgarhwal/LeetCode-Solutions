/* Question: Single Number II
 * Lang: cpp
 * Runtime: 8 ms
 * Memory: 8.8 MB
 * Question Url: https://leetcode.com/problems/single-number-ii
 * Submission Url:
 * https://leetcode.com/problems/single-number-ii/submissions/313024059
 */

class Solution {
public:
  int singleNumber(vector<int> &nums) {
    int one = 0, two = 0;

    for (auto x : nums) {

      one = (one ^ x) & (~two);

      two = (two ^ x) & (~one);
    }
    return one;
  }
};
