/*
Problem Title: 662 - Maximum Width of Binary Tree
Lang: C++
Runtime: 12 ms
Memory: 17.4 MB
Problem Url: https://leetcode.com/problems/maximum-width-of-binary-tree
Submission Url: https://leetcode.com/problems/maximum-width-of-binary-tree/submissions/936951145
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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int res = 1;

        queue<pair<TreeNode*, int>> q;        
        q.push({root, 0});
        
        while(!q.empty()) {

            int cnt = q.size();
            int start = q.front().second;
            int end = q.back().second;
            
            res = max(res, end-start + 1);
            
            for(int i = 0; i < cnt; i++) {
                pair<TreeNode*, int> p = q.front();
                q.pop();

                int idx = p.second - start;
                
                if(p.first->left != NULL) {
                    q.push({p.first->left, (long long)2 * idx + 1});
                }
                
                if(p.first->right != NULL) {
                    q.push({p.first->right, (long long) 2 * idx + 2});
                }
            }
        }
        
        return res;
    }
};