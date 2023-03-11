/*
Problem Title: 382 - Linked List Random Node
Lang: C++
Runtime: 22 ms
Memory: 16.6 MB
Problem Url: https://leetcode.com/problems/linked-list-random-node
Submission Url: https://leetcode.com/problems/linked-list-random-node/submissions/912383864
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
    ListNode* head;

public:
    Solution(ListNode* head) {
        this->head = head;
        srand(time(NULL));
    }
    
    int getRandom() {
        int scope = 1, ans = 0;
        ListNode* cur = this->head;

        while(cur != NULL) {
            if(((float)rand() / RAND_MAX) < 1.0/scope) {
                ans = cur->val;
            }
            scope += 1;
            cur = cur->next;
        }

        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */