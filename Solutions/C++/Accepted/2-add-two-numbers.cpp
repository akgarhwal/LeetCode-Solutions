/*
Problem Title: 2 - Add Two Numbers
Lang: C++
Runtime: 81 ms
Memory: 71.4 MB
Problem Url: https://leetcode.com/problems/add-two-numbers
Submission Url: https://leetcode.com/problems/add-two-numbers/submissions/766070569
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int sum = 0, carry = 0;
        ListNode *head = NULL;
        ListNode *cur = NULL;
        
        sum = l1->val + l2->val;
        
        head = new ListNode(sum%10);
        cur = head;
        carry = sum/10;
        l1 = l1->next;
        l2 = l2->next;
        
        while(l1 != NULL and l2 != NULL){
            
            sum = l1->val + l2->val + carry;
            // head init
            cur->next = new ListNode(sum%10);
            cur = cur->next;
            carry = sum/10;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1 != NULL){
            sum = l1->val + carry;
            // head init
            cur->next = new ListNode(sum%10);
            cur = cur->next;
            carry = sum/10;
            l1 = l1->next;
        }
        
        while(l2 != NULL){
            sum = l2->val + carry;
            // head init
            cur->next = new ListNode(sum%10);
            cur = cur->next;
            carry = sum/10;
            l2 = l2->next;
        }
        
        if(carry) {
            cur->next = new ListNode(carry);
        }
        
        return head;
    }
};