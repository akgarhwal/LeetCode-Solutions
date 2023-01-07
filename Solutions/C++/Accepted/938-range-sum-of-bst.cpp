/*
Problem Title: 938 - Range Sum of BST
Lang: C++
Runtime: 148 ms
Memory: 40.2 MB
Problem Url: https://leetcode.com/problems/range-sum-of-bst
Submission Url: https://leetcode.com/problems/range-sum-of-bst/submissions/310846716
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
    
    void dfs(TreeNode* root, int L, int R, int& ans){
        if(root == NULL){
            return;
        }
        
        if(root->val < L){
            dfs(root->right,L,R,ans);
        }
        if(root->val > R){
            dfs(root->left,L,R,ans);
        }
        if(root->val >=L and root->val <= R){
            ans += root->val;
            dfs(root->left,L,R,ans);
            dfs(root->right,L,R,ans);
        }
    }
    
    int rangeSumBST(TreeNode* root, int L, int R) {
        int ans = 0;
        dfs(root, L,R,ans);
        return ans;
    }
};