/*
Problem Title: 993 - Cousins in Binary Tree
Lang: C++
Runtime: 4 ms
Memory: 10.9 MB
Problem Url: https://leetcode.com/problems/cousins-in-binary-tree
Submission Url: https://leetcode.com/problems/cousins-in-binary-tree/submissions/335647438
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
    int x_parent = -1, y_parent = -1, x_depth = -1, y_depth = -1;
public:
    void helper(TreeNode* root, int x, int y, int depth, int parent){
        if(root == NULL){
            return;
        }        
        if(root->val == x){
            x_parent = parent;
            x_depth = depth;
        }
        if(root->val == y){
            y_parent = parent;
            y_depth = depth;
        }
        if(root->val == x){
            x_parent = parent;
            x_depth = depth;
        }
        if(root->val == y){
            y_parent = parent;
            y_depth = depth;
        }
        helper(root->left,x,y,depth+1, root->val);
        helper(root->right,x,y,depth+1, root->val);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        if(root->val == x || root->val == y){
            return false;
        }
        helper(root, x, y, 0, -1);
        if(x_depth == y_depth && x_depth != -1 && x_parent != y_parent && x_parent != -1 && x_parent != -1){
            return true;
        }
        return false;
    }
};