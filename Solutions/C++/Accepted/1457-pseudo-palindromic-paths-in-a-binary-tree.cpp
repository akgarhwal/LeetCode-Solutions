/*
Problem Title: 1457 - Pseudo-Palindromic Paths in a Binary Tree
Lang: C++
Runtime: 216 ms
Memory: 107.3 MB
Problem Url: https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree
Submission Url: https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/submissions/344198330
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
    int ans = 0;
    vector<int> ar = vector(10,0);
        
    void helper(TreeNode* root){
        ar[root->val]++;
        if(root->left == NULL and root->right == NULL){
            int co = 0;
            for(int x : ar){
                if(x % 2 == 1){
                    co++;
                }
            }
            if(co <= 1){
                ans++;
            }
        }
        
        if(root->left != NULL){
            helper(root->left);
        }
        if(root->right != NULL){
            helper(root->right);
        }
        ar[root->val]--;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        ans = 0;
        helper(root);
        
        return ans;
    }
};