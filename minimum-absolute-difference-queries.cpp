/* Question: Minimum Absolute Difference Queries
 * Lang: cpp
 * Runtime: 500 ms
 * Memory: 88.1 MB
 * Question Url:
 * https://leetcode.com/problems/minimum-absolute-difference-queries Submission
 * Url:
 * https://leetcode.com/problems/minimum-absolute-difference-queries/submissions/510451358
 */

class Solution {
public:
  vector<int> minDifference(vector<int> &nums, vector<vector<int>> &queries) {
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < nums.size(); i++) {
      mp[nums[i]].push_back(i);
    }

    vector<int> res;
    for (int i = 0; i < queries.size(); i++) {
      int f = -1, s = -1;
      int ans = 1;
      int mr = INT_MAX;
      while (f == -1 and ans <= 100) {
        if (mp[ans].size() == 0) {
          ans++;
          continue;
        };
        int ub = lower_bound(mp[ans].begin(), mp[ans].end(), queries[i][0]) -
                 mp[ans].begin();
        int lb = upper_bound(mp[ans].begin(), mp[ans].end(), queries[i][1]) -
                 mp[ans].begin();
        if (ub < lb) {
          f = ans;
        }
        ans++;
      }
      while (ans <= 100) {

        if (mp[ans].size() == 0) {
          ans++;
          continue;
        };
        int ub = lower_bound(mp[ans].begin(), mp[ans].end(), queries[i][0]) -
                 mp[ans].begin();
        int lb = upper_bound(mp[ans].begin(), mp[ans].end(), queries[i][1]) -
                 mp[ans].begin();
        if (ub < lb) {
          s = ans;
          if (mr > (s - f)) {
            mr = s - f;
          }
          f = s;
        }
        if (mr == 1) {
          break;
        }
        ans++;
      }
      if (mr == INT_MAX) {
        mr = -1;
      }
      res.push_back(mr);
    }
    return res;
  }
};
