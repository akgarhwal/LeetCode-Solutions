/* Question: Count Good Nodes in Binary Tree
 * Lang: cpp
 * Runtime: 195 ms
 * Memory: 86.4 MB
 * Question Url: https://leetcode.com/problems/count-good-nodes-in-binary-tree
 * Submission Url:
 * https://leetcode.com/problems/count-good-nodes-in-binary-tree/submissions/788577183
 */

/**
  * Definition for a binary tree node.
  * struct TreeNode {
  *     int val;
  *     TreeNode *left;
  *     TreeNode *right;
  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  * };
  */


class Solution {
public:
  int ans = 0;
  void helper(TreeNode *root, int mx) {
    if (root == NULL) {
      return;
    }

    if (root->val >= mx) {
      ans++;
    }

    helper(root->left, max(mx, root->val));
    helper(root->right, max(mx, root->val));
  }

  int goodNodes(TreeNode *root) {
    ans = 0;
    helper(root, root->val);
    return ans;
  }
};
