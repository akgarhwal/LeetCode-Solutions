/*
Problem Title: 337 - House Robber III
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/house-robber-iii
Submission Url: https://leetcode.com/problems/house-robber-iii/submissions/597199925
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
    int fun(TreeNode* root, bool flag){
        if(root == NULL){
            return 0;
        }
        int p1 = 0;
        if(flag){
            p1 = root->val + fun(root->left, false) + fun(root->right, false);
        }
        
        return max( p1, max(fun(root->left, false) + fun(root->right, false), fun(root->left, true) + fun(root->right, true)  ));
        
    }
    int rob(TreeNode* root) {
        return max(fun(root, true), fun(root, false));
    }
};