/* Question: Linked List in Binary Tree
 * Lang: cpp
 * Runtime: 36 ms
 * Memory: 23.5 MB
 * Question Url: https://leetcode.com/problems/linked-list-in-binary-tree
 * Submission Url:
 * https://leetcode.com/problems/linked-list-in-binary-tree/submissions/308148338
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    bool isSubPath(ListNode* head, TreeNode* root) {
        return isSubPathUtil(head, root);
    }
    
    bool isSubPathUtil(ListNode* head, TreeNode* root, bool isStarted = false){
        
        if(root == NULL and head == NULL){
            return true;
        }
        if(root == NULL and head != NULL){
            return false;
        }
        if(head == NULL){
            return true;
        }

        if(root->val != head->val and isStarted == true){
            return false;
        }
            
        bool res = false;
        if(root->val == head->val){
            res = res or isSubPathUtil(head->next, root->left, true);
            res = res or isSubPathUtil(head->next, root->right, true);
        }
        
        if(isStarted == false){
            res = res or isSubPathUtil(head, root->left, isStarted);
            res = res or isSubPathUtil(head, root->right, isStarted);
        }
        
        return res;
        
    }
    
    
};
