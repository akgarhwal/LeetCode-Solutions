/* Question: Validate Binary Tree Nodes
 * Lang: cpp
 * Runtime: 52 ms
 * Memory: 12.1 MB
 * Question Url: https://leetcode.com/problems/validate-binary-tree-nodes
 * Submission Url:
 * https://leetcode.com/problems/validate-binary-tree-nodes/submissions/305961861
 */

class Solution {
public:
  bool validateBinaryTreeNodes(int n, vector<int> &leftChild,
                               vector<int> &rightChild) {
    if (n == 1) {
      return true;
    }
    // first is out nad seocnd is in
    vector<pair<int, int>> tree(n, {0, 0});
    int edges = 0;
    for (int ind = 0; ind < leftChild.size(); ind++) {

      if (leftChild[ind] != -1) {

        edges += 1;

        tree[ind].first += 1;
        tree[leftChild[ind]].second += 1;
      }
    }
    for (int ind = 0; ind < rightChild.size(); ind++) {

      if (rightChild[ind] != -1) {

        edges += 1;

        tree[ind].first += 1;
        tree[rightChild[ind]].second += 1;
      }
    }

    if (edges != (n - 1))
      return false;

    bool ans = true;
    int co = 0;
    for (int i = 0; i < n; i++) {

      if (tree[i].first == 0 and tree[i].second == 0) {
        cout << "IN";
        ans = false;
        break;
      }

      if (tree[i].second > 1) {
        cout << "OUT";
        ans = false;
        break;
      }
    }
    return ans;
  }
};
