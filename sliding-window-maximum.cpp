/* Question: Sliding Window Maximum
 * Lang: cpp
 * Runtime: 296 ms
 * Memory: 145.8 MB
 * Question Url: https://leetcode.com/problems/sliding-window-maximum
 * Submission Url:
 * https://leetcode.com/problems/sliding-window-maximum/submissions/503719961
 */

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < k; i++) {
      pq.push({nums[i], i});
    }
    vector<int> ans;
    ans.push_back(pq.top().first);
    int i = k;
    while (i < nums.size()) {
      pq.push({nums[i], i});
      while (pq.top().second <= (i - k)) {
        pq.pop();
      }
      ans.push_back(pq.top().first);
      i++;
    }
    return ans;
  }
};
