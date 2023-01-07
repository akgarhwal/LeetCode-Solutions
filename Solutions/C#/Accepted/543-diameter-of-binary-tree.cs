/*
Problem Title: 543 - Diameter of Binary Tree
Lang: C#
Runtime: 84 ms
Memory: 25.5 MB
Problem Url: https://leetcode.com/problems/diameter-of-binary-tree
Submission Url: https://leetcode.com/problems/diameter-of-binary-tree/submissions/305654208
*/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public int DiameterOfBinaryTree(TreeNode root) {
        int ans = 0;
        DiameterOfBinaryTreeHelper(root, ref ans);
        return ans;
    }
    
    private int DiameterOfBinaryTreeHelper(TreeNode root, ref int ans){
        if(root == null) {
            return 0;
        }
        int left_height = DiameterOfBinaryTreeHelper(root.left, ref ans);
        int right_height = DiameterOfBinaryTreeHelper(root.right, ref ans);
        ans = Math.Max(ans, left_height + right_height);
        return Math.Max(left_height, right_height) + 1;
    }
}