/*
Problem Title: 783 - Minimum Distance Between BST Nodes
Lang: C++
Runtime: 0 ms
Memory: 9.7 MB
Problem Url: https://leetcode.com/problems/minimum-distance-between-bst-nodes
Submission Url: https://leetcode.com/problems/minimum-distance-between-bst-nodes/submissions/899552999
*/

class Solution {
public:
    void helper(TreeNode* root, int& minDiff, int& prevVal) {
        if (root == nullptr)
            return;
        helper(root -> left, minDiff, prevVal);
        if (prevVal != -1) {
            minDiff = min(minDiff, root -> val - prevVal);
        }
        prevVal = root -> val;
        helper(root -> right, minDiff, prevVal);
        
    }
    int minDiffInBST(TreeNode* root) {
        int minDiff = INT_MAX;
        int prevVal = -1;
        helper(root, minDiff, prevVal);
        return minDiff;
    }
};
