/* Question: Find the Town Judge
 * Lang: cpp
 * Runtime: 440 ms
 * Memory: 70.9 MB
 * Question Url: https://leetcode.com/problems/find-the-town-judge
 * Submission Url:
 * https://leetcode.com/problems/find-the-town-judge/submissions/611911357
 */

class Solution {
public:
  int findJudge(int n, vector<vector<int>> &trust) {
    if (n == 1) {
      return n;
    }
    map<int, int> mp, mp2;
    for (auto x : trust) {
      mp[x[1]]++;
      mp2[x[0]]++;
    }

    for (auto x : mp) {
      if (x.second == n - 1 and mp2[x.first] == 0) {
        return x.first;
      }
    }
    return -1;
  }
};
