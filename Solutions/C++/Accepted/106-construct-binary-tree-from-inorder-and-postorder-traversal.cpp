/*
Problem Title: 106 - Construct Binary Tree from Inorder and Postorder Traversal
Lang: C++
Runtime: 34 ms
Memory: 26 MB
Problem Url: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal
Submission Url: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/submissions/916289291
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

    TreeNode* buildTreeHelper(vector<int>& inorder, int inOrderLeft, int inOrderRight, vector<int>& postorder, int postOrderLeft, int postOrderRight){
        if(postOrderLeft > postOrderRight or inOrderLeft > inOrderRight) {
            return NULL;
        }

        TreeNode* node = new TreeNode(postorder[postOrderRight]);
        int rootIndex = inOrderLeft;  
        while(node->val != inorder[rootIndex]) {
            rootIndex += 1;
        }
        node->left  = buildTreeHelper(inorder, inOrderLeft, rootIndex-1, postorder, postOrderLeft, postOrderLeft + rootIndex-inOrderLeft-1);
        node->right = buildTreeHelper(inorder, rootIndex+1, inOrderRight, postorder, postOrderLeft + rootIndex - inOrderLeft, postOrderRight-1);
        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTreeHelper(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
};