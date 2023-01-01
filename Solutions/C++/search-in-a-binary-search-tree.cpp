/* Question: Search in a Binary Search Tree
 * Lang: cpp
 * Runtime: 72 ms
 * Memory: 34.9 MB
 * Question Url: https://leetcode.com/problems/search-in-a-binary-search-tree
 * Submission Url:
 * https://leetcode.com/problems/search-in-a-binary-search-tree/submissions/353947055
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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL){
            return NULL;
        }
        if(root->val == val){
            return root;
        }
        if(root->val < val){
            return searchBST(root->right, val);
        }
        return searchBST(root->left, val);
    }
};
