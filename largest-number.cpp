/* Question: Largest Number
 * Lang: cpp
 * Runtime: 16 ms
 * Memory: 8.9 MB
 * Question Url: https://leetcode.com/problems/largest-number
 * Submission Url:
 * https://leetcode.com/problems/largest-number/submissions/306445018
 */

bool mySort(int x, int y) {

  string xy = to_string(x) + to_string(y);
  string yx = to_string(y) + to_string(x);

  return xy > yx;
}
class Solution {
public:
  string largestNumber(vector<int> &nums) {

    sort(nums.begin(), nums.end(), mySort);

    string res = "";
    int z_count = 0;
    for (auto num : nums) {
      if (num == 0) {
        z_count += 1;
      }
      res += to_string(num);
    }
    if (z_count == nums.size()) {
      res = "0";
    }
    return res;
  }
};
