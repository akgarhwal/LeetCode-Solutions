/*
Problem Title: 102 - Binary Tree Level Order Traversal
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/binary-tree-level-order-traversal
Submission Url: https://leetcode.com/problems/binary-tree-level-order-traversal/submissions/308678465
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<pair<TreeNode*, int>> que;
        que.push({root, 0});
        while( !que.empty() ){
            
            auto ele = que.front();que.pop();
            if(ele.second >= ans.size()){
                vector<int> te(1, ele.first->val);
                ans.push_back(te);
            }
            else{
                ans[ele.second].push_back(ele.first->val);
            }
            
            if(ele.first->left != NULL){
                que.push({ele.first->left, ele.second + 1});
            }
            if(ele.first->right != NULL){
                que.push({ele.first->right, ele.second + 1});
            }
            
        }
        return ans;
    }
};