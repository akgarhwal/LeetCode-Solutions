/*
Problem Title: 142 - Linked List Cycle II
Lang: C++
Runtime: 10 ms
Memory: 7.6 MB
Problem Url: https://leetcode.com/problems/linked-list-cycle-ii
Submission Url: https://leetcode.com/problems/linked-list-cycle-ii/submissions/765539321
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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != NULL and fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
            if(fast == NULL){
                return NULL;
            }
            fast = fast->next;
            if(fast == slow){
                break;
            }
        }
        
        if(fast == NULL or fast->next == NULL) {
            return NULL;
        }
        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};