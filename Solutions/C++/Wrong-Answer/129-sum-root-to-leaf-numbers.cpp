/*
Problem Title: 129 - Sum Root to Leaf Numbers
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/sum-root-to-leaf-numbers
Submission Url: https://leetcode.com/problems/sum-root-to-leaf-numbers/submissions/914686662
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

    void solve(TreeNode* root, int& num, int& sum) {
        if(root == NULL) {
            sum += num;
            return;
        }

        num = num*10 + (root->val);

        solve(root->left, num, sum);
        solve(root->right, num, sum);

        num = num / 10;
    }

    int sumNumbers(TreeNode* root) {
        int ans = 0, num = 0;

        solve(root, num, ans);
        
        return ans>>1;
    }
};