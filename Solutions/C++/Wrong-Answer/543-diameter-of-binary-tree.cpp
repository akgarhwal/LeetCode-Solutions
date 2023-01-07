/*
Problem Title: 543 - Diameter of Binary Tree
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/diameter-of-binary-tree
Submission Url: https://leetcode.com/problems/diameter-of-binary-tree/submissions/322972196
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
    
    int helper(TreeNode* root, int& ans){
        if(root == NULL){
            return 0;
        }
        int left = helper(root->left, ans);
        int right = helper(root->right, ans);
        ans = max({ans, left, right, left+right});
        return max(left,right)+1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = INT_MIN;
        helper(root, ans);
        return ans;
    }
};