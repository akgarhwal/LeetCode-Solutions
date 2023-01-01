/* Question: Maximum Gap
 * Lang: cpp
 * Runtime: 8 ms
 * Memory: 9.7 MB
 * Question Url: https://leetcode.com/problems/maximum-gap
 * Submission Url:
 * https://leetcode.com/problems/maximum-gap/submissions/500357927
 */

class Solution {
public:
  int maximumGap(vector<int> &nums) {
    if (nums.size() < 2) {
      return 0;
    }
    int mi = INT_MAX, mx = INT_MIN;
    for (int x : nums) {
      mi = min(mi, x);
      mx = max(mx, x);
    }
    int interval = ceil((mx - mi) / (double)(nums.size() - 1));
    if (interval == 0) {
      return 0;
    }
    map<int, pair<int, int>> bucket;

    for (int num : nums) {
      int index = (num - mi) / interval;
      if (bucket.find(index) != bucket.end()) {
        bucket[index].first = min(num, bucket[index].first);
        bucket[index].second = max(num, bucket[index].second);
      } else {
        bucket[index] = {num, num};
      }
    }
    int ans = interval;
    for (auto it = bucket.begin(); it != bucket.end(); it++) {
      auto next_it = it;
      next_it++;
      if (next_it != bucket.end()) {
        ans = max(ans, next_it->second.first - it->second.second);
      }
    }
    return ans;
  }
};
