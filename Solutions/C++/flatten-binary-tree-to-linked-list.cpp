/* Question: Flatten Binary Tree to Linked List
 * Lang: cpp
 * Runtime: 8 ms
 * Memory: 12.8 MB
 * Question Url:
 * https://leetcode.com/problems/flatten-binary-tree-to-linked-list Submission
 * Url:
 * https://leetcode.com/problems/flatten-binary-tree-to-linked-list/submissions/493338598
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
  void flatten(TreeNode *root) {
    while (root) {
      if (root->left && root->right) {
        TreeNode *t = root->left;
        while (t->right)
          t = t->right;
        t->right = root->right;
      }

      if (root->left)
        root->right = root->left;
      root->left = NULL;
      root = root->right;
    }
  }
};
