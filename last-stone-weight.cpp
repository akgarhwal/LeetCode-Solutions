/* Question: Last Stone Weight
 * Lang: cpp
 * Runtime: 2 ms
 * Memory: 7.5 MB
 * Question Url: https://leetcode.com/problems/last-stone-weight
 * Submission Url:
 * https://leetcode.com/problems/last-stone-weight/submissions/774955345
 */

class Solution {
public:
  int lastStoneWeight(vector<int> &stones) {

    while (stones.size() > 1) {
      sort(stones.begin(), stones.end());
      int n = stones.size();
      int y = stones[n - 1];
      int x = stones[n - 2];
      stones.pop_back();
      stones.pop_back();

      if (x != y) {
        stones.push_back(y - x);
      }
    }
    return stones.size() == 0 ? 0 : stones[0];
  }
};
