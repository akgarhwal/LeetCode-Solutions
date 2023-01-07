/* Question: Convert Sorted Array to Binary Search Tree
 * Lang: cpp
 * Runtime: 25 ms
 * Memory: 21.3 MB
 * Question Url:
 * https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree
 * Submission Url:
 * https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/submissions/769886349
 */

/**
  * Definition for a binary tree node.
  * struct TreeNode {
  *     int val;
  *     TreeNode *left;
  *     TreeNode *right;
  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  * };
  */

class Solution {
public:
  TreeNode *solve(vector<int> &nums, int left, int right) {
    if (left > right) {
      return NULL;
    }

    int mid = (left + right) >> 1;

    TreeNode *root = new TreeNode(nums[mid]);

    root->left = solve(nums, left, mid - 1);
    root->right = solve(nums, mid + 1, right);

    return root;
  }

  TreeNode *sortedArrayToBST(vector<int> &nums) {

    return solve(nums, 0, nums.size() - 1);
  }
};