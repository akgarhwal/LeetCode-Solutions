/*
Problem Title: 2368 - Reachable Nodes With Restrictions
Lang: C++
Runtime: 1561 ms
Memory: 204.7 MB
Problem Url: https://leetcode.com/problems/reachable-nodes-with-restrictions
Submission Url: https://leetcode.com/problems/reachable-nodes-with-restrictions/submissions/767377872
*/

class Solution {
public:
    void dfs(int s, vector<vector<int>> &adj, set<int>& restricted, int &ans) {
        if(restricted.find(s) != restricted.end()){
            return;
        }
        ans += 1;
        restricted.insert(s);
        for(int i=0; i < adj[s].size(); i++) {
            
            dfs(adj[s][i], adj, restricted, ans);
        }
    }
    
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> adj(n, vector<int>());
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        set<int> restrictedSet(restricted.begin(), restricted.end());
        
        int ans = 0;
        dfs(0, adj, restrictedSet, ans);
        return ans;
    }
};