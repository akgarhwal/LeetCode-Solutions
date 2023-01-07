/*
Problem Title: 1008 - Construct Binary Search Tree from Preorder Traversal
Lang: C++
Runtime: 4 ms
Memory: 11.1 MB
Problem Url: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal
Submission Url: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/submissions/343911195
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
    TreeNode* helper(int index, int end, vector<int>& preorder){
        if(index > end){
            return NULL;
        }
        
        TreeNode* root = new TreeNode(preorder[index]);
        int left_end = index;
        for(int i = index+1; i < preorder.size(); i++){
            if(preorder[i] < preorder[index]){
                left_end = i;
            }
        }
        
        root->left = helper(index+1, left_end, preorder);
        root->right = helper(left_end+1, end, preorder);
        
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return helper(0, preorder.size()-1, preorder);
    }
};