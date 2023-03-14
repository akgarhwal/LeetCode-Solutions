/*
Problem Title: 101 - Symmetric Tree
Lang: C++
Runtime: 8 ms
Memory: 16.5 MB
Problem Url: https://leetcode.com/problems/symmetric-tree
Submission Url: https://leetcode.com/problems/symmetric-tree/submissions/914075008
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

    bool isMirror(TreeNode* left, TreeNode* right, bool& ans) {
        if(!ans){
            return ans;
        }

        if(left == NULL and right == NULL) {
            return true;
        }

        if( (left == NULL and right != NULL) or (left != NULL and right == NULL) or left->val != right->val ) {
            return ans = false;
        }

        return isMirror(left->left, right->right, ans) and isMirror(left->right, right->left, ans);
    }

    bool isSymmetric(TreeNode* root) {
        if(root == NULL) {
            return true;
        }
        bool ans = true;
        return isMirror(root->left, root->right, ans);
    }
};