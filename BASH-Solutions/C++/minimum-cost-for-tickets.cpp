/* Question: Minimum Cost For Tickets
 * Lang: cpp
 * Runtime: 0 ms
 * Memory: 9.5 MB
 * Question Url: https://leetcode.com/problems/minimum-cost-for-tickets
 * Submission Url:
 * https://leetcode.com/problems/minimum-cost-for-tickets/submissions/486336891
 */

class Solution {
public:
  int mincostTickets(vector<int> &days, vector<int> &costs) {
    vector<int> dp(days[days.size() - 1] + 1, 10000);

    dp[0] = 0;
    int i = 0;
    for (int day = 1; day <= days[days.size() - 1]; day++) {
      if (i < days.size() && day == days[i]) {
        i++;
        dp[day] = min(dp[day], (day - 1 >= 0 ? dp[day - 1] : 0) + costs[0]);
        dp[day] = min(dp[day], (day - 7 >= 0 ? dp[day - 7] : 0) + costs[1]);
        dp[day] = min(dp[day], (day - 30 >= 0 ? dp[day - 30] : 0) + costs[2]);
      } else {
        dp[day] = dp[day - 1];
      }
    }
    return dp[days[days.size() - 1]];
  }
};
