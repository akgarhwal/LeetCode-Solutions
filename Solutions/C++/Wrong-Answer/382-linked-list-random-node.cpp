/*
Problem Title: 382 - Linked List Random Node
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/linked-list-random-node
Submission Url: https://leetcode.com/problems/linked-list-random-node/submissions/912378754
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
    ListNode* cur;
    ListNode* head;
public:
    Solution(ListNode* head) {
        this->head = head;
        this->cur = head;
    }
    
    int getRandom() {
        if(this->cur == NULL) {
            this->cur = this->head;
        }
        int val = this->cur->val;
        this->cur = this->cur->next;
        return val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */