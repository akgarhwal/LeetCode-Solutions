/*
Problem Title: 958 - Check Completeness of a Binary Tree
Lang: C++
Runtime: 7 ms
Memory: 10.8 MB
Problem Url: https://leetcode.com/problems/check-completeness-of-a-binary-tree
Submission Url: https://leetcode.com/problems/check-completeness-of-a-binary-tree/submissions/915327778
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

    void helper(TreeNode* root, vector<int>& lc) {
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            
            auto node = q.front(); q.pop();
            if(node == NULL){
                lc.push_back(-1);
            } else {
                lc.push_back(node->val);
                q.push(node->left);
                q.push(node->right);
            }
        }
    }

    bool isCompleteTree(TreeNode* root) {
        vector<int> lc;
        
        helper(root, lc);

        bool found = false;
        
        for(int i=0; i < lc.size(); i++) {

            if(found and lc[i] != -1) {
                return false;
            }

            if(lc[i] == -1 and !found) {
                found = true;
            }
        }

        return true;
    }
};