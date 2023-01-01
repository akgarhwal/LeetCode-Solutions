/* Question: Lowest Common Ancestor of a Binary Search Tree
 * Lang: cpp
 * Runtime: 35 ms
 * Memory: 23.3 MB
 * Question Url:
 * https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree
 * Submission Url:
 * https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/submissions/771572446
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
        
        
        return fun(root, p->val,q->val);
        
    }
    
    TreeNode* fun(TreeNode* root, int p, int q) {
        
        if(root == NULL) return NULL;
        
        if(p < root->val and q < root->val){
            return fun(root->left, p, q);
        }
        
        if( (p <= root->val && q >= root->val) or (q <= root->val && p >= root->val)) {
            
            return root;
            
        }
        
        return fun(root->right, p, q);
    }
};
