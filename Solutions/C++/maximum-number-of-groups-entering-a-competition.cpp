/* Question: Maximum Number of Groups Entering a Competition
 * Lang: cpp
 * Runtime: 147 ms
 * Memory: 56.6 MB
 * Question Url:
 * https://leetcode.com/problems/maximum-number-of-groups-entering-a-competition
 * Submission Url:
 * https://leetcode.com/problems/maximum-number-of-groups-entering-a-competition/submissions/764899706
 */

class Solution {
public:
  int maximumGroups(vector<int> &grades) {

    sort(grades.begin(), grades.end());

    int ans = 0;
    int cur_sum = 0, last_sum = 0, last_count = 0, cur_count = 0;

    for (int i = 0; i < grades.size(); i++) {
      cur_sum += grades[i];
      cur_count += 1;
      if (cur_sum > last_sum and cur_count > last_count) {
        ans += 1;
        last_sum = cur_sum;
        last_count = cur_count;
        cur_count = cur_sum = 0;
      }
    }

    return ans;
  }
};
