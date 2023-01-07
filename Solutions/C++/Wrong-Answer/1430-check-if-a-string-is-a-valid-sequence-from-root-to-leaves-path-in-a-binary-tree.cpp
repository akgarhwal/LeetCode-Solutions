/*
Problem Title: 1430 - Check If a String Is a Valid Sequence from Root to Leaves Path in a Binary Tree
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/check-if-a-string-is-a-valid-sequence-from-root-to-leaves-path-in-a-binary-tree
Submission Url: https://leetcode.com/problems/check-if-a-string-is-a-valid-sequence-from-root-to-leaves-path-in-a-binary-tree/submissions/332165607
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
    
    bool helper(TreeNode* root, vector<int>& arr, int index){
        if(root == NULL and arr.size() == index){
            return true;
        }
        if(root == NULL or arr.size() == index){
            return false;
        }
        
        bool ans = false;
        
        if(root->val == arr[index]){
            ans = ans or helper(root->left, arr, index+1);
            ans = ans or helper(root->right, arr, index+1);
        }
        return ans;
    }
    
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        return helper(root, arr, 0);
    }
};