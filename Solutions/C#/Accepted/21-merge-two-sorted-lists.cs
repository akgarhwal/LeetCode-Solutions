/*
Problem Title: 21 - Merge Two Sorted Lists
Lang: C#
Runtime: 84 ms
Memory: 25.7 MB
Problem Url: https://leetcode.com/problems/merge-two-sorted-lists
Submission Url: https://leetcode.com/problems/merge-two-sorted-lists/submissions/305643080
*/

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode MergeTwoLists(ListNode l1, ListNode l2) {
        
        if(l1 == null){
            return l2;
        }
        if(l2 == null){
            return l1;
        }
        
        ListNode head = null;
        if(l1.val < l2.val){
            head = l1;
            l1 = l1.next;
        }else{
            head = l2;
            l2 = l2.next;
        }
        
        head.next = MergeTwoLists(l1,l2);
        return head;
    }
}