/*
Problem Title: 589 - N-ary Tree Preorder Traversal
Lang: C++
Runtime: 54 ms
Memory: 11 MB
Problem Url: https://leetcode.com/problems/n-ary-tree-preorder-traversal
Submission Url: https://leetcode.com/problems/n-ary-tree-preorder-traversal/submissions/767528489
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    
    void solve(Node* root, vector<int> &ans){
        if(root == NULL) {
            return;
        }
        ans.push_back(root->val);
        
        for(auto child : root->children){
            solve(child, ans);
        }
    }
    
    vector<int> preorder(Node* root) {
        
        vector<int> ans;
        solve(root, ans);
        return ans;
    }
};