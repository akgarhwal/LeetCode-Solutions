/*
Problem Title: 687 - Longest Univalue Path
Lang: C++
Runtime: 120 ms
Memory: 71.7 MB
Problem Url: https://leetcode.com/problems/longest-univalue-path
Submission Url: https://leetcode.com/problems/longest-univalue-path/submissions/484936291
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
    int longestUnivaluePath(TreeNode* root) {
        
        int ans = 0;
        return max(ans, fun(root, ans));
    }
    
    int fun(TreeNode* root, int &ans) {
        if(root == NULL) return -1;
        
        if(root->left == NULL && root->right == NULL){
            return 0;
        }
        
        int LV = fun(root->left, ans);
        int RV = fun(root->right, ans);
        
        if(root->left != NULL && root->right != NULL) {
            
            if(root->left->val == root->val && root->right->val == root->val) {
                
                ans = max(ans, LV+RV+2);
                return 1+max(LV,RV);

            }
            
            if(root->left->val == root->val) {
                ans = max(ans, LV+1);
                return 1+LV;
            }
            
            if(root->right->val == root->val) {
                ans = max(ans,RV+1);
                return 1+RV;
            }
           
        }
        
        if(root->left == NULL && root->right->val == root->val){
            ans = max(ans, LV+1);
            return 1+RV;
        }
        
        if(root->right == NULL && root->left->val == root->val){
            ans = max(ans, RV+1);
            return 1+LV;
        }
        return 0;
        
    }
};