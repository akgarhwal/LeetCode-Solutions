/*
Problem Title: 226 - Invert Binary Tree
Lang: C#
Runtime: 92 ms
Memory: 24 MB
Problem Url: https://leetcode.com/problems/invert-binary-tree
Submission Url: https://leetcode.com/problems/invert-binary-tree/submissions/305609487
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
    public TreeNode InvertTree(TreeNode root) {
        if (root == null){
            return root;
        }
        TreeNode temp = root.left;
        root.left = InvertTree(root.right);
        root.right = InvertTree(temp);
        return root;
    }
}