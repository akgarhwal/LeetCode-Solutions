/*
Problem Title: 124 - Binary Tree Maximum Path Sum
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/binary-tree-maximum-path-sum
Submission Url: https://leetcode.com/problems/binary-tree-maximum-path-sum/submissions/331714163
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
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        maxPathSumHelper(root, ans);
        return ans;
    }
    
    int maxPathSumHelper(TreeNode* root, int& ans){
        if(root == NULL){
            return 0;
        }
        
        int left_sum = maxPathSumHelper(root->left, ans);
        int right_sum = maxPathSumHelper(root->right, ans);
        
        ans = max({ans, root->val, left_sum + root->val, right_sum + root->val,left_sum + right_sum + root->val});
        
        return  max({left_sum+root->val, right_sum+root->val});
    }
};