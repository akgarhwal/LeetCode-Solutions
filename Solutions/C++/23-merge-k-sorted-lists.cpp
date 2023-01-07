/*
Problem Title: 23 - Merge k Sorted Lists
Lang: C++
Runtime: 664 ms
Memory: 12.9 MB
Problem Url: https://leetcode.com/problems/merge-k-sorted-lists
Submission Url: https://leetcode.com/problems/merge-k-sorted-lists/submissions/504217971
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode* head = NULL;
        ListNode* current = NULL;
        
        ListNode* node = getSmallestNode(lists);
        head = node;
        current = node;
        while( node != NULL){
            node = getSmallestNode(lists);
            current->next = node;
            current = current->next;
        }
        return head;        
    }
    
    ListNode* getSmallestNode(vector<ListNode*>& lists){
        
        ListNode* smallest_node = NULL;
        int mi = INT_MAX, idx = -1;
        for(int i = 0 ; i < lists.size(); i++){
            if(lists[i] != NULL and mi > lists[i]->val){
                smallest_node = lists[i];
                mi = lists[i]->val;
                idx = i;
            }
        }
        if(idx != -1)
            lists[idx] = lists[idx]->next;
        return smallest_node;     
    }
};