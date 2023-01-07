/*
Problem Title: 1430 - Check If a String Is a Valid Sequence from Root to Leaves Path in a Binary Tree
Lang: C++
Runtime: 96 ms
Memory: 48.9 MB
Problem Url: https://leetcode.com/problems/check-if-a-string-is-a-valid-sequence-from-root-to-leaves-path-in-a-binary-tree
Submission Url: https://leetcode.com/problems/check-if-a-string-is-a-valid-sequence-from-root-to-leaves-path-in-a-binary-tree/submissions/332179627
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
        // if(root == NULL and arr.size() == index){
        //     return true;
        // }
        if(root == NULL or arr.size() == index){
            return false;
        }
        
        if(root->val == arr[index] and root->left == NULL and root->right == NULL and arr.size()-1 == index){
            return true;   
        }
        bool ans = false;
        if(root->val == arr[index] and root->left != NULL){
            ans = ans or helper(root->left, arr, index+1);
        }
        if(root->val == arr[index] and root->right != NULL){
            ans = ans or helper(root->right, arr, index+1);
        }
        return ans;
    }
    
    
    //[0,1,0,0,1,0,null,null,1,0,0], arr = [0,1,0,1]
    
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        return helper(root, arr, 0);
    }
};