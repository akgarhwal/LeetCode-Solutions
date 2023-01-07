/*
Problem Title: 876 - Middle of the Linked List
Lang: C++
Runtime: 3 ms
Memory: 7 MB
Problem Url: https://leetcode.com/problems/middle-of-the-linked-list
Submission Url: https://leetcode.com/problems/middle-of-the-linked-list/submissions/765499431
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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL and fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;   
    }
};