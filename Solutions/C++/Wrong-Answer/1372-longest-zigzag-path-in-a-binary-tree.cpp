/*
Problem Title: 1372 - Longest ZigZag Path in a Binary Tree
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree
Submission Url: https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/submissions/310176598
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int ans = 0;
class Solution {
public:
    int helper(TreeNode* root, int dir){
        if(root == NULL){
            return -1;
        }
        int he = 0;
        int he2 = 0;
        
        if(dir == 0){
            he = helper(root->right, 1-dir);
            he2 = helper(root->left, 0);
        }
        else{
            he = helper(root->left, 1-dir);
            he2 = helper(root->right, 1);
        }
        
        ans = max(ans, max(he, he2)+1);
        cout<<root->val<<" :: "<<he<<" :: "<<he2<<endl;
        if(he2 > he+1){
            cout<<" :: 0"<<endl;
            return 0;
        }
        cout<<max(he+1,he2)<<endl;
        return  max(he+1,he2);
    }
    int longestZigZag(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        ans = 0;
        int left = helper(root, 0);
        int right = helper(root, 1);
        //ans = max(ans, max(left, right) + 1);
        return max(ans, 0);
    }
};