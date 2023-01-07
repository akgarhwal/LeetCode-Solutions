/*
Problem Title: 1377 - Frog Position After T Seconds
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/frog-position-after-t-seconds
Submission Url: https://leetcode.com/problems/frog-position-after-t-seconds/submissions/310392307
*/

double ans  = 0.0;
bool found = false;
class Solution {
public:
    bool isLeafNode(map<int, vector<int>>& tree, set<int>& visited, int node){
        
        bool res = true;
        for(auto it : tree[node]){
            
            if(visited.count(it) == 0){
                res = false;
                break;
            }
            
        }
        return res;
    }
    void helper(map<int, vector<int>>& tree, int cur, int sec, int tar, int t, double prob, set<int>& visited){
        //cout<<cur<<" : " << sec<< " : " << prob <<endl;
        //cout<<"TC : "<<tree.count(cur)<<endl;
        //leaf node
        visited.insert(cur);
        
        if(cur == tar and sec <= t and isLeafNode(tree, visited, cur) ){
            ans =  prob;
            return;
        }
        // middle node with same time
        if(cur == tar and sec == t and isLeafNode(tree, visited, cur) == false ){
            ans = prob;
            return;
        }
        
        
        if(cur == tar and sec != t and isLeafNode(tree, visited, cur) == false ){
            ans = 0.0;
            return;
        }
        // need to check
        if(isLeafNode(tree, visited, cur)){
            return;
        }
        for(int i=0;i<tree[cur].size();i++){
            
            double sz = (double)tree[cur].size();
            if(cur != 1){
                sz -=1.0;
            }
            if(visited.count(tree[cur][i]) == 0)
                helper(tree, tree[cur][i], sec+1,tar, t, prob / (sz), visited);
            
        }
        
    }
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        ans = 1.0;
        map<int, vector<int>> tree;
        for(int i = 0; i< edges.size();i++){
            
            int from = edges[i][0];
            int to = edges[i][1];
            if(tree.count(from) == 0){
                vector<int> temp;
                tree[from] = temp;
            }
            if(tree.count(to) == 0){
                vector<int> temp;
                tree[to] = temp;
            }
            
            tree[from].push_back(to);
            tree[to].push_back(from);
        }
        //tree[1].push_back(-1);
        set<int> visited;
        helper(tree, 1, 0, target, t, 1, visited);
        
        return ans;
        
    }
};