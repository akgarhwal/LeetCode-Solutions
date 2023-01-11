/*
Problem Title: 100 - Same Tree
Lang: C++
Runtime: 0 ms
Memory: 10 MB
Problem Url: https://leetcode.com/problems/same-tree
Submission Url: https://leetcode.com/problems/same-tree/submissions/875075098
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL and q == NULL) {
            return true;
        }
        if(p == NULL and q != NULL) {
            return false;
        }
        if(q == NULL and p != NULL) {
            return false;
        }

        if(p->val != q->val){
            return false;
        }

        return isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
    }
};