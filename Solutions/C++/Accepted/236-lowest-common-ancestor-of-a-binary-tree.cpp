/*
Problem Title: 236 - Lowest Common Ancestor of a Binary Tree
Lang: C++
Runtime: 19 ms
Memory: 14.2 MB
Problem Url: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree
Submission Url: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/submissions/756857236
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        
        TreeNode* ans = NULL;
        
        fun(root, p->val,q->val,ans);
        
        return ans;
    }
    
    bool fun(TreeNode* root, int p, int q, TreeNode* &ans) {
        
        if(root == NULL) return false;
        
        
        int left = fun(root->left, p, q, ans);
        
        int right = fun(root->right, p, q, ans);
        
        if((left or right) and (root->val == p or root->val == q)) {
            ans = root;
        }
        
        if(left && right){
            ans = root;
        }
        
        
        return left or right or root->val == p or root->val == q;
        
    }
};