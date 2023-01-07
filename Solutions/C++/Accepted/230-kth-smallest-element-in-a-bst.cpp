/*
Problem Title: 230 - Kth Smallest Element in a BST
Lang: C++
Runtime: 24 ms
Memory: 24.3 MB
Problem Url: https://leetcode.com/problems/kth-smallest-element-in-a-bst
Submission Url: https://leetcode.com/problems/kth-smallest-element-in-a-bst/submissions/342291017
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
    
    void helper(TreeNode* root, int k, int& ans, int& count){
        if(root==NULL or ans != -1){
            return;
        }
        
        if(root->left == NULL and root->right == NULL){
            count++;
            if(count == k){
                ans = root->val;
                return;
            }
            return;
        }
        helper(root->left, k, ans, count);
        count++;
        if(count == k){
            ans = root->val;
            return;
        }
        helper(root->right, k, ans, count);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1, co = 0;
        helper(root, k, ans, co);
        return ans;
    }
};