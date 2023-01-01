/* Question: Binary Tree Right Side View
 * Lang: cpp
 * Runtime: 0 ms
 * Memory: 12 MB
 * Question Url: https://leetcode.com/problems/binary-tree-right-side-view
 * Submission Url:
 * https://leetcode.com/problems/binary-tree-right-side-view/submissions/484905334
 */

/**
  * Definition for a binary tree node. 
  * struct TreeNode {
  *     int val;
  *     TreeNode *left;
  *     TreeNode *right; 
  *     TreeNode() : val(0), left(nullptr), right(nullptr) {} 
  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} 
  *     TreeNode(int x,TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  * };
  */
class Solution {
public:
  vector<int> rightSideView(TreeNode *root) {
    queue<pair<TreeNode *, int>> queue;
    queue.push({root, 0});
    int pLevel = -1;
    vector<int> ans;
    if (root == NULL)
      return ans;
    cout << root->val << endl;
    while (!queue.empty()) {

      auto pi = queue.front();
      queue.pop();
      if (pi.second > pLevel) {
        ans.push_back(pi.first->val);
        pLevel = pi.second;
      }
      if (pi.first->right != NULL) {
        queue.push({pi.first->right, pi.second + 1});
      }
      if (pi.first->left != NULL) {
        queue.push({pi.first->left, pi.second + 1});
      }
    }
    return ans;
  }
};
