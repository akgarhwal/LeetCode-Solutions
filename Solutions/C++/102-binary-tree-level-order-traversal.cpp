/*
Problem Title: 102 - Binary Tree Level Order Traversal
Lang: C++
Runtime: 13 ms
Memory: 13.6 MB
Problem Url: https://leetcode.com/problems/binary-tree-level-order-traversal
Submission Url: https://leetcode.com/problems/binary-tree-level-order-traversal/submissions/767556144
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
    
    void dfs(TreeNode* root, int level, vector<vector<int>> &ans){
        if(root == NULL){
            return;
        }
        if(ans.size() == level) {
            ans.push_back(vector<int>());
        }
        ans[level].push_back(root->val);
        dfs(root->left, level+1, ans);
        dfs(root->right, level+1, ans);
        
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        dfs(root, 0, ans);
        return ans;
    }
};