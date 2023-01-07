/*
Problem Title: 328 - Odd Even Linked List
Lang: C++
Runtime: 4 ms
Memory: 10.6 MB
Problem Url: https://leetcode.com/problems/odd-even-linked-list
Submission Url: https://leetcode.com/problems/odd-even-linked-list/submissions/595919746
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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL){return head;}
        ListNode *first = head, *second = head->next;
        ListNode *temp = second;
        while(second != NULL && second->next != NULL){
            
            first->next = second->next;
            first = first->next;
            second->next = first->next;
            second = second->next;
        }
        
        first->next = temp;
        return head;
    }
};