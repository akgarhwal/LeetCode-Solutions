/*
Problem Title: 1382 - Balance a Binary Search Tree
Lang: C++
Runtime: 184 ms
Memory: 52.1 MB
Problem Url: https://leetcode.com/problems/balance-a-binary-search-tree
Submission Url: https://leetcode.com/problems/balance-a-binary-search-tree/submissions/312528868
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
class Solution {
public:
    
    void in_order(TreeNode* root, vector<int>& arr){
        
        if(root == NULL){
            return;
        }
        in_order(root->left, arr);
        arr.push_back(root->val);
        in_order(root->right, arr);
    }
    
    
    
    TreeNode* sortedArrayToBST(vector<int>& arr, int start, int end)  
    {  
        if (start > end)  
        return NULL;
       
        int mid = (start + end)/2;  
        TreeNode* root = new TreeNode(arr[mid]);  
        
        root->left = sortedArrayToBST(arr, start,  mid - 1);  

        root->right = sortedArrayToBST(arr, mid + 1, end);  

        return root;  
    }  
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        
        in_order(root, arr);
        
        return sortedArrayToBST(arr, 0, arr.size()-1);
    }
};