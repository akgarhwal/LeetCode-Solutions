/*
Problem Title: 94 - Binary Tree Inorder Traversal
Lang: C++
Runtime: 4 ms
Memory: 8.5 MB
Problem Url: https://leetcode.com/problems/binary-tree-inorder-traversal
Submission Url: https://leetcode.com/problems/binary-tree-inorder-traversal/submissions/506622822
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* temp = root;
        
        while(temp != NULL or !st.empty()){
            while(temp != NULL){
                st.push(temp);
                temp = temp->left;
            }
            temp = st.top(); st.pop();
            ans.push_back(temp->val);
            temp = temp->right;            
        }
        
        return ans;
    }
};