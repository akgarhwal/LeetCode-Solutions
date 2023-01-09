/*
Problem Title: 144 - Binary Tree Preorder Traversal
Lang: C++
Runtime: 0 ms
Memory: 8.4 MB
Problem Url: https://leetcode.com/problems/binary-tree-preorder-traversal
Submission Url: https://leetcode.com/problems/binary-tree-preorder-traversal/submissions/874392670
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

    void solve(TreeNode* root, vector<int>& preOrder){
        if(root == NULL){
            return;
        }
        preOrder.push_back(root->val);
        solve(root->left, preOrder);
        solve(root->right, preOrder);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preOrder;
        solve(root, preOrder);
        return preOrder;
    }
};