/*
Problem Title: 2583 - Kth Largest Sum in a Binary Tree
Lang: C++
Runtime: 216 ms
Memory: 99.4 MB
Problem Url: https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree
Submission Url: https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/submissions/909369093
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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        vector<long long> arr;        
        long long sum = 0;
        
        while(!q.empty()){
            
            TreeNode* temp = q.front();
            q.pop();
            
            if(temp == NULL){
                continue;
            }
            sum += temp->val;
            
            if(temp -> left) {
                q.push(temp->left);
            }
            if(temp -> right) {
                q.push(temp->right);
            }
            
            if(q.front() == NULL){
                arr.push_back(sum);  
                sum = 0;
                q.push(NULL);
            }
        }
        
        if(k > arr.size()){
            return -1;
        }

        sort(arr.begin(), arr.end());
        return arr[arr.size()-k];
    }
};
