/*
Problem Title: 21 - Merge Two Sorted Lists
Lang: C++
Runtime: 12 ms
Memory: 14.9 MB
Problem Url: https://leetcode.com/problems/merge-two-sorted-lists
Submission Url: https://leetcode.com/problems/merge-two-sorted-lists/submissions/764690974
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = NULL;
        ListNode* current = NULL;
        
        if(list1 == NULL){
            return list2;
        }
        if(list2 == NULL){
            return list1;
        }
        
        if(list1->val < list2-> val){
            head = list1;
            list1 = list1->next;
        } else {
            head = list2;
            list2 = list2->next;
        }
        current = head;
        
        while(list1 != NULL and list2 != NULL){
            if(list1->val < list2->val){
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }
        if(list1 != NULL){
            current->next = list1;
        }
        if(list2 != NULL){
            current->next = list2;
        }
        return head;
    }
};