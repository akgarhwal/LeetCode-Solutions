/*
Problem Title: 1372 - Longest ZigZag Path in a Binary Tree
Lang: C++
Runtime: 200 ms
Memory: 66.4 MB
Problem Url: https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree
Submission Url: https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/submissions/310182466
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
int ans = 0;
class Solution {
public:
    int helper(TreeNode* root, int dir){
        if(root == NULL){
            return -1;
        }
        int count = 0;
        int count2 = 0;
        
        if(dir == 0){
            count = helper(root->right, 1-dir);
            count2 = helper(root->left, 0);
        }
        else{
            count = helper(root->left, 1-dir);
            count2 = helper(root->right, 1);
        }
        
        ans = max(ans, max(count, count2)+1);
        return count+1;
    }
    int longestZigZag(TreeNode* root) {
        ans = 0;
        helper(root, 0);
        helper(root, 1);
        return max(ans, 0);
    }
};