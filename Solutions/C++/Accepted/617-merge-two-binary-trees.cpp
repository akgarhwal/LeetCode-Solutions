/*
Problem Title: 617 - Merge Two Binary Trees
Lang: C++
Runtime: 48 ms
Memory: 26.2 MB
Problem Url: https://leetcode.com/problems/merge-two-binary-trees
Submission Url: https://leetcode.com/problems/merge-two-binary-trees/submissions/305487513
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL && t2 == NULL){
            return NULL;
        }
        
        if (t1 != NULL && t2 == NULL){
            TreeNode* new_node = new TreeNode(t1->val);
            new_node->left = t1->left;
            new_node->right = t1->right;
            return new_node;
        }
        
        if (t1 == NULL && t2 != NULL){
            TreeNode* new_node = new TreeNode(t2->val);
            new_node->left = t2->left;
            new_node->right = t2->right;
            return new_node;
        }
        
        TreeNode* new_node = new TreeNode(t1->val + t2->val);
        new_node->left = mergeTrees(t1->left, t2->left);
        new_node->right = mergeTrees(t1->right, t2->right);
        return new_node;
    }
};