/*
Problem Title: 652 - Find Duplicate Subtrees
Lang: C++
Runtime: 24 ms
Memory: 36.8 MB
Problem Url: https://leetcode.com/problems/find-duplicate-subtrees
Submission Url: https://leetcode.com/problems/find-duplicate-subtrees/submissions/906518186
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

    string solve(TreeNode* root, vector<TreeNode*>& result, unordered_map<string, int>& ht) {
        if(root == NULL) {
            return "";
        }

        string subTreeStr = "(" + solve(root->left, result, ht) + ")" + to_string(root->val) + "(" + solve(root->right, result, ht) + ")";
        ht[subTreeStr] += 1;
        if(ht[subTreeStr] == 2) {
            result.push_back(root);
        }
        return subTreeStr;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> result;
        unordered_map<string, int> ht;

        solve(root, result, ht);
        return result;
    }
};