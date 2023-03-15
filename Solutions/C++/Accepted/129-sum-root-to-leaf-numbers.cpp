/*
Problem Title: 129 - Sum Root to Leaf Numbers
Lang: C++
Runtime: 0 ms
Memory: 9.3 MB
Problem Url: https://leetcode.com/problems/sum-root-to-leaf-numbers
Submission Url: https://leetcode.com/problems/sum-root-to-leaf-numbers/submissions/914689624
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

    void solve(TreeNode* root, int num, int& sum) {
        if(root == NULL) {
            sum += num;
            return;
        }
        
        num = num*10 + (root->val);

        if(root->left == NULL and root->right == NULL) {
            sum += num;
            return;
        }

        if (root->left != NULL) {
            solve(root->left, num, sum);
        }
        if (root->right != NULL) {
            solve(root->right, num, sum);
        }
    }

    int sumNumbers(TreeNode* root) {
        int ans = 0, num = 0;

        solve(root, num, ans);
        
        return ans;
    }
};