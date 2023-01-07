/*
Problem Title: 226 - Invert Binary Tree
Lang: C++
Runtime: 0 ms
Memory: 8.3 MB
Problem Url: https://leetcode.com/problems/invert-binary-tree
Submission Url: https://leetcode.com/problems/invert-binary-tree/submissions/347674325
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
    TreeNode* invertTree(TreeNode* root) {
        
        if(root == NULL){
            return root;
        }
        
        TreeNode* temp = root->left;
        
        root->left = invertTree(root->right);
        root->right = invertTree(temp);
        
        return root;
    }
};