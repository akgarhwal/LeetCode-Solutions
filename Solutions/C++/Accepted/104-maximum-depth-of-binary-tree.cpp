/*
Problem Title: 104 - Maximum Depth of Binary Tree
Lang: C++
Runtime: 10 ms
Memory: 18.9 MB
Problem Url: https://leetcode.com/problems/maximum-depth-of-binary-tree
Submission Url: https://leetcode.com/problems/maximum-depth-of-binary-tree/submissions/898823247
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
    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }

        return max(maxDepth(root->left) ,maxDepth(root->right) )+1; 
    }
};