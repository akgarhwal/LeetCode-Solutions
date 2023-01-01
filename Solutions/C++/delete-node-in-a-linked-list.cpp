/* Question: Delete Node in a Linked List
 * Lang: cpp
 * Runtime: 12 ms
 * Memory: 8 MB
 * Question Url: https://leetcode.com/problems/delete-node-in-a-linked-list
 * Submission Url:
 * https://leetcode.com/problems/delete-node-in-a-linked-list/submissions/347957567
 */

/**
  * Definition for singly-linked list.
  * struct ListNode {
  *     int val;
  *     ListNode *next;
  *     ListNode(int x) : val(x), next(NULL) {}
  * };
  */


class Solution {
public:
  void deleteNode(ListNode *node) {
    ListNode *temp = node->next;

    node->next = node->next->next;
    node->val = temp->val;

    // free(temp);
  }
};
