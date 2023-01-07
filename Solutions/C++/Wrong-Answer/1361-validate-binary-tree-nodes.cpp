/*
Problem Title: 1361 - Validate Binary Tree Nodes
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/validate-binary-tree-nodes
Submission Url: https://leetcode.com/problems/validate-binary-tree-nodes/submissions/305958513
*/

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        // first is out nad seocnd is in
        vector<pair<int,int>> tree(n,{0,0});
        int edges = 0;
        for(int ind = 0; ind < leftChild.size(); ind++){
            
            if(leftChild[ind] != -1){
                
                edges += 1;
                
                tree[ind].first += 1;
                tree[leftChild[ind]].second += 1;
                
            }
            
        }
        for(int ind = 0; ind < rightChild.size(); ind++){
            
            if(rightChild[ind] != -1){
                
                edges += 1;
                
                tree[ind].first += 1;
                tree[rightChild[ind]].second += 1;
                
            }
            
        }
        
        if(edges != (n-1)) return false;
        
        bool ans = true;
        int co = 0;
        for(int i = 0;i < n; i++){
            
            if(tree[i].first > 1 and co == 1){
                ans = false;
                break;
            }
            
            if(tree[i].first > 1){
                co = 1;
            }
            
            if(tree[i].first == 0 and tree[i].second == 0){
                ans = false;
                break;
            }
            
            if(tree[i].second > 1){
                ans = false;
                break;
            }
            
        }
        return ans;
    }
};