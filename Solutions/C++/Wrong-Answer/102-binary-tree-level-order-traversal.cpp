/*
Problem Title: 102 - Binary Tree Level Order Traversal
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/binary-tree-level-order-traversal
Submission Url: https://leetcode.com/problems/binary-tree-level-order-traversal/submissions/495696877
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        unordered_map<int, vector<int>> mp;
        int ml = 0;
        while(!q.empty()) {
            auto ele = q.front();q.pop();
            if(ele.first != NULL) {
                int level = ele.second;
                mp[level].push_back(ele.first->val);
                ml = max(ml, level);
                q.push({ele.first->left, level+1});
                q.push({ele.first->right, level+1});
            }
        }
        
        vector<vector<int>> ans;
        for(int i = 0; i <= ml; i++){
            ans.push_back(mp[i]);
        }
        return ans;
    }
};