/*
Problem Title: 105 - Construct Binary Tree from Preorder and Inorder Traversal
Lang: C++
Runtime: 23 ms
Memory: 26.3 MB
Problem Url: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal
Submission Url: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/submissions/746720925
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        unordered_map<int,int> mp;
        for(int i=0; i < inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        
        return fun(0, 0, preorder.size()-1, preorder, mp);
    }
    
    TreeNode* fun(int index, int lm, int rm, vector<int>& preorder, unordered_map<int,int>& mp){
        
        if(index >= preorder.size()) {
            return NULL;
        }
        
        int node_val = preorder[index];
        
        TreeNode* node = new TreeNode(node_val);
        
        int inorder_index = mp[node_val];
        
        if(lm < inorder_index){
            node->left = fun(index+1, lm, inorder_index-1, preorder, mp);
        }
        if(inorder_index < rm){
            node->right = fun(index + (inorder_index-lm) + 1, inorder_index+1, rm, preorder, mp);
        }
        
        return node;
    }
    
};