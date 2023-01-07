/*
Problem Title: 206 - Reverse Linked List
Lang: C++
Runtime: 25 ms
Memory: 8.6 MB
Problem Url: https://leetcode.com/problems/reverse-linked-list
Submission Url: https://leetcode.com/problems/reverse-linked-list/submissions/764682805
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
class Solution {
public:
    ListNode* reverse(ListNode* head, ListNode* prev) {
        if(head == NULL){
            return head;
        }
        if(head->next == NULL){
            head->next = prev;
            return head;
        }
        ListNode* newHead = reverse(head->next, head);
        head->next = prev;
        return newHead;
    }
    ListNode* reverseList(ListNode* head) {
        return reverse(head, NULL);
    }
};