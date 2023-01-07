/*
Problem Title: 92 - Reverse Linked List II
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/reverse-linked-list-ii
Submission Url: https://leetcode.com/problems/reverse-linked-list-ii/submissions/512063879
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *temp = head, *prev = NULL, *temp2 = head;
        
        while(temp != NULL and temp->val != left){
            prev = temp;
            temp = temp->next;
        }
        while(temp2 != NULL and temp2->val != right){
            temp2 = temp2->next;
        }
        if(temp2 != NULL)
            temp2 = temp2->next;
        
        ListNode* rev_head = (temp == NULL) ? NULL : rev(temp, NULL, right);
        
        if(prev != NULL){
            prev->next = rev_head;
        }
        else{
            head = rev_head;
        }
        
        while(rev_head != NULL and rev_head->next != NULL){
            rev_head = rev_head->next;
        }
        if(rev_head != NULL) 
            rev_head->next = temp2;
        return head;
    }
    
    ListNode* rev(ListNode* head, ListNode* prev, int right){
        if(head->next == NULL or head->val == right){
            head->next = prev;
            return head;
        }
        ListNode* new_head = rev(head->next, head, right);
        head->next = prev;
        return new_head;
    }
};