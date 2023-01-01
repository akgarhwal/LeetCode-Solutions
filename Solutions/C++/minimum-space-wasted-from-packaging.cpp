/* Question: Minimum Space Wasted From Packaging
 * Lang: cpp
 * Runtime: 300 ms
 * Memory: 116.2 MB
 * Question Url:
 * https://leetcode.com/problems/minimum-space-wasted-from-packaging Submission
 * Url:
 * https://leetcode.com/problems/minimum-space-wasted-from-packaging/submissions/503705548
 */

class Solution {
public:
  int minWastedSpace(vector<int> &packages, vector<vector<int>> &boxes) {
    sort(packages.begin(), packages.end());

    long long ans = 1e18;

    vector<long> psum(packages.size(), 0);
    psum[0] = packages[0];
    for (int i = 1; i < packages.size(); i++) {
      psum[i] = psum[i - 1] + packages[i];
    }

    for (vector<int> &box : boxes) {
      sort(box.begin(), box.end());

      long long temp = 0;
      int i = 0, j = 0;
      while (i < packages.size() and j < box.size()) {
        int idx = upper_bound(packages.begin() + i, packages.end(), box[j]) -
                  packages.begin();

        if (idx == i) {
          j++;
          continue;
        }
        idx--;
        temp += ((box[j] * 1LL * (idx - i + 1)) -
                 (psum[idx] - (i > 0 ? psum[i - 1] : 0)));
        i = idx + 1;
        j++;
      }
      if (i == packages.size())
        ans = min(ans, temp);
    }
    return ans == 1e18 ? -1 : ans % 1000000007;
  }
};

// 2 3 5
// 2 5 10
