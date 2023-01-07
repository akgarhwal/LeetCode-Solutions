/*
Problem Title: 92 - Reverse Linked List II
Lang: C++
Runtime: 8 ms
Memory: 7.4 MB
Problem Url: https://leetcode.com/problems/reverse-linked-list-ii
Submission Url: https://leetcode.com/problems/reverse-linked-list-ii/submissions/752534719
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
        ListNode *cur = head, *prev = NULL, *rev_st = NULL,*rev_end = NULL,*end = NULL, *last_st = NULL;
        
        int ind = 1;
        while ( cur != NULL){
            if(ind < left){
                end = cur;
            }
            if(ind > right and last_st == NULL){
                last_st = cur;
            }
            
            if(ind >= left and ind <= right){
                if(rev_st == NULL){
                    rev_st = cur;
                }
                rev_end = cur;
                ListNode* nx = cur->next;
                cur->next = prev;
                prev = cur;
                cur = nx;
            }
            else{
                cur = cur->next;
            }
            ind += 1;            
        }
        if(end != NULL){
            end->next = rev_end;
        }
        else{
            head = rev_end;
        }
        if(rev_st != NULL){
            rev_st->next = last_st; 
        }
        return head;
    }
};