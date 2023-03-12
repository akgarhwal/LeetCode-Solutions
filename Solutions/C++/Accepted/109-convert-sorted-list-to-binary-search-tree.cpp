/*
Problem Title: 109 - Convert Sorted List to Binary Search Tree
Lang: C++
Runtime: 31 ms
Memory: 28.5 MB
Problem Url: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree
Submission Url: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/submissions/912967879
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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

    TreeNode* solve(vector<int>& nums, int left, int right) {
        if(left > right){
            return NULL;
        }
        
        int mid = (left + right) >> 1;
        
        TreeNode* root = new TreeNode(nums[mid]);
        
        root->left = solve(nums, left, mid-1);
        root->right = solve(nums, mid+1, right);
        
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;

        while(head != NULL) {
            nums.push_back(head->val);
            head = head->next;
        }

        return solve(nums, 0, nums.size()-1);
    }
};