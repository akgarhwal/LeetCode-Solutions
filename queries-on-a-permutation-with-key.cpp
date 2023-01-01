/* Question: Queries on a Permutation With Key
 * Lang: cpp
 * Runtime: 32 ms
 * Memory: 8.2 MB
 * Question Url: https://leetcode.com/problems/queries-on-a-permutation-with-key
 * Submission Url:
 * https://leetcode.com/problems/queries-on-a-permutation-with-key/submissions/323547725
 */

class Solution {
public:
  int getPos(int q, vector<int> &per) {
    int ind = -1;
    for (int i = 0; i < per.size(); i++) {
      if (q == per[i]) {
        ind = i;
        break;
      }
    }
    return ind;
  }
  vector<int> processQueries(vector<int> &queries, int m) {

    vector<int> ans;
    vector<int> per(m, 0);
    for (int i = 0; i < m; i++) {
      per[i] = i + 1;
    }

    for (int q : queries) {

      int pos = getPos(q, per);
      ans.push_back(pos);
      per.erase(per.begin() + pos);
      per.insert(per.begin(), q);
    }
    return ans;
  }
};
