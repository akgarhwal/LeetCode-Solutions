/*
Problem Title: 297 - Serialize and Deserialize Binary Tree
Lang: C++
Runtime: 88 ms
Memory: 47 MB
Problem Url: https://leetcode.com/problems/serialize-and-deserialize-binary-tree
Submission Url: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/submissions/503216173
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL){
            return "N";
        }
        
        string ans = to_string(root->val);
        ans += "," + serialize(root->left);
        ans += "," + serialize(root->right);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q = tokenize(data);
        return buildTree(q, NULL);
    }
    
    TreeNode* buildTree(queue<string> &q, TreeNode* root){
        string val = q.front();q.pop();
        if(val != "N"){
            TreeNode* node = new TreeNode(to_int(val));
            node->left = buildTree(q, root);
            node->right = buildTree(q, root);
            return node;
        }
        return NULL;
    }
    
    queue<string> tokenize(string s, string del = ",")
    {
        queue<string> ans;
        int start = 0;
        int end = s.find(del);
        while (end != -1) {
            string temp = s.substr(start, end - start);
            ans.push(temp);
            start = end + del.size();
            end = s.find(del, start);
        }
        string temp = s.substr(start, end - start);
        ans.push(temp);
        return ans;
    }
    int to_int(string s){
        int ans = 0;
        int index = s[0] == '-' ? 1 : 0;
        for(int i = index; i < s.size(); i++){
            ans = ans*10 + int(s[i] - '0');
        }
        
        return index == 1 ? ans * -1 : ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));