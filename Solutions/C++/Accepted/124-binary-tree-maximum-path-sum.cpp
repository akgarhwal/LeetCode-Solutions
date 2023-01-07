/*
Problem Title: 124 - Binary Tree Maximum Path Sum
Lang: C++
Runtime: 40 ms
Memory: 28.6 MB
Problem Url: https://leetcode.com/problems/binary-tree-maximum-path-sum
Submission Url: https://leetcode.com/problems/binary-tree-maximum-path-sum/submissions/331714513
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
            return INT_MIN;
        }
        
        int left_sum = maxPathSumHelper(root->left, ans);
        int right_sum = maxPathSumHelper(root->right, ans);
        
        ans = max(left_sum, max(right_sum, ans));
        if(left_sum != INT_MIN)
            ans = max(ans, left_sum + root->val);
        if(right_sum != INT_MIN)
            ans = max(ans, right_sum + root->val);
        if (left_sum != INT_MIN && right_sum != INT_MIN){
            ans = max(ans, left_sum + right_sum + root->val);
        }
        ans = max(ans, root->val);
        return root->val + max(left_sum, max(right_sum, 0));
    }
};