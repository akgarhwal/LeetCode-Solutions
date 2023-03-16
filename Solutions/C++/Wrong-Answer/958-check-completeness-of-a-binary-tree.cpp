/*
Problem Title: 958 - Check Completeness of a Binary Tree
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/check-completeness-of-a-binary-tree
Submission Url: https://leetcode.com/problems/check-completeness-of-a-binary-tree/submissions/915326300
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

    void helper(TreeNode* root, int level, vector<int>& lc) {
        if(root == NULL) {
            lc.push_back(-1);
            return;
        }
        if(root->left == NULL and root->right == NULL) {
            lc.push_back(root->val);
            return;
        }
        
       lc.push_back(root->val);

        helper(root->left, level+1, lc);
        helper(root->right, level+1, lc);
    }

    bool isCompleteTree(TreeNode* root) {
        vector<int> lc;
        helper(root, 0, lc);

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