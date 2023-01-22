/*
Problem Title: 1315 - Sum of Nodes with Even-Valued Grandparent
Lang: C++
Runtime: 57 ms
Memory: 41.3 MB
Problem Url: https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent
Submission Url: https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/submissions/882133297
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

    void solve(TreeNode* root, TreeNode* parent, TreeNode* grandParent, int &sum) {
        if(root == NULL){
            return;
        }
        if(parent != NULL and grandParent != NULL and ((grandParent->val)%2) == 0) {
            sum += root->val;
        }
        solve(root->left, root, parent, sum);
        solve(root->right, root, parent, sum);
    }

    int sumEvenGrandparent(TreeNode* root) {
        int sum = 0;
        solve(root, NULL, NULL, sum);
        return sum;
    }
};