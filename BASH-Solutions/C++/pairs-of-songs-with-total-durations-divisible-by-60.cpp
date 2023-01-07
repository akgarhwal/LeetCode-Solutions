/* Question: Pairs of Songs With Total Durations Divisible by 60
 * Lang: cpp
 * Runtime: 58 ms
 * Memory: 23.1 MB
 * Question Url:
 * https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60
 * Submission Url:
 * https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/submissions/611256194
 */

class Solution {
public:
  int numPairsDivisibleBy60(vector<int> &time) {
    unordered_map<int, int> freqMap;
    for (int x : time) {
      freqMap[x % 60] += 1;
    }

    int ans = 0;
    for (int x : time) {
      x = x % 60;
      if (x == 0) {
        ans += freqMap[x] - 1;
      } else if (x != 30) {
        ans += freqMap[60 - x];
      } else {
        ans += freqMap[60 - x] - 1;
      }
    }
    return ans >> 1;
  }
};
