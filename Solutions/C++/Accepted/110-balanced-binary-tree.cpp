/*
Problem Title: 110 - Balanced Binary Tree
Lang: C++
Runtime: 17 ms
Memory: 21 MB
Problem Url: https://leetcode.com/problems/balanced-binary-tree
Submission Url: https://leetcode.com/problems/balanced-binary-tree/submissions/940384609
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

    int helper(TreeNode* root, bool& ans) {
        if(!ans) {
            return 0;
        }

        if(root == NULL) {
            return 0;
        }

        if(root->left == NULL and root->right == NULL) {
            return 1;
        }

        int left = helper(root->left, ans);
        int right = helper(root->right, ans);
        
        if(abs(left-right) > 1){
            ans = false;
        }
        return max(left, right) + 1;
    }

    bool isBalanced(TreeNode* root) {
        bool ans = true;
        
        helper(root, ans);

        return ans;
    }
};