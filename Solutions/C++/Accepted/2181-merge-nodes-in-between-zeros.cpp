/*
Problem Title: 2181 - Merge Nodes in Between Zeros
Lang: C++
Runtime: 787 ms
Memory: 274.5 MB
Problem Url: https://leetcode.com/problems/merge-nodes-in-between-zeros
Submission Url: https://leetcode.com/problems/merge-nodes-in-between-zeros/submissions/881747659
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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* start = NULL;
        ListNode* current = head;
        ListNode* newCurrent = start;
        int sum = 0;

        current = current->next;
        while(current != NULL) {
            sum += current->val;
            if(current->val == 0){
                if(newCurrent == NULL){
                    newCurrent = new ListNode(sum);
                    start = newCurrent;
                } else {
                    newCurrent->next = new ListNode(sum);
                    newCurrent = newCurrent->next;
                }
                sum = 0;
            }
            current = current->next;
        }
        return start;
    }
};