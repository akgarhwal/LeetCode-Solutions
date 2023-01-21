/*
Problem Title: 1302 - Deepest Leaves Sum
Lang: C++
Runtime: 103 ms
Memory: 59.9 MB
Problem Url: https://leetcode.com/problems/deepest-leaves-sum
Submission Url: https://leetcode.com/problems/deepest-leaves-sum/submissions/881632487
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

    void solve(TreeNode* root, int level, int& mxLevel, int& sum) {
        if(root == NULL) {
            return;
        }

        if(level > mxLevel) {
            mxLevel = level;
            sum = 0;
        }

        if(level == mxLevel) {
            sum += root->val;
        }

        solve(root->left, level+1, mxLevel, sum);
        solve(root->right, level+1, mxLevel, sum);
    }

    int deepestLeavesSum(TreeNode* root) {
        int sum = 0, mxLevel = 0;
        solve(root, 0, mxLevel, sum);
        return sum;
    }
};