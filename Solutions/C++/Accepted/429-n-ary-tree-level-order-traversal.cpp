/*
Problem Title: 429 - N-ary Tree Level Order Traversal
Lang: C++
Runtime: 11 ms
Memory: 11.9 MB
Problem Url: https://leetcode.com/problems/n-ary-tree-level-order-traversal
Submission Url: https://leetcode.com/problems/n-ary-tree-level-order-traversal/submissions/947266499
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
    vector<vector<int>> levelOrder(Node* root) {
        
        vector<vector<int>> ans;

        if(root == NULL) {
            return ans;
        }

        int level = 0;
        queue<pair<Node*, int>> q;
        q.push({root, 0});

        while(!q.empty()) {

            auto ele = q.front(); q.pop();

            if(ele.second >= ans.size()) {
                vector<int> temp;
                temp.push_back(ele.first->val);
                ans.push_back(temp);
            } else {
                ans[ele.second].push_back(ele.first->val);
            }

            for(auto child : ele.first->children) {
                q.push({child, ele.second + 1});
            }
        }

        return ans;
    }
};