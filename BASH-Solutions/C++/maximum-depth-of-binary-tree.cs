/* Question: Maximum Depth of Binary Tree
 * Lang: csharp
 * Runtime: 96 ms
 * Memory: 25.4 MB
 * Question Url: https://leetcode.com/problems/maximum-depth-of-binary-tree
 * Submission Url:
 * https://leetcode.com/problems/maximum-depth-of-binary-tree/submissions/303445201
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
    public int MaxDepth(TreeNode root) {
        if(root == null){
            return 0;
        }
        return Math.Max(MaxDepth(root.left), MaxDepth(root.right)) + 1;
    }
}
