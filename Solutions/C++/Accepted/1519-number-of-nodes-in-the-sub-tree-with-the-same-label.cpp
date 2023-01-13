/*
Problem Title: 1519 - Number of Nodes in the Sub-Tree With the Same Label
Lang: C++
Runtime: 2460 ms
Memory: 441.3 MB
Problem Url: https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label
Submission Url: https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/submissions/876481789
*/

class Solution {
public:

    unordered_map<char, int> solve(int source, int n, vector<vector<int>>& graph, string& labels, vector<bool>& vis, vector<int>& ans) {

        unordered_map<char, int> localMap;
        if(source >= n) {
            return localMap;
        }
        if(vis[source]){
            return localMap;
        }
        vis[source] = true;

        for(int i=0; i < graph[source].size(); i++){
            int newSource = graph[source][i];
            if(vis[newSource]){
                continue;
            }
            auto localMap2 = solve(newSource, n, graph, labels, vis, ans);
            for(auto kv : localMap2){
                localMap[kv.first] += kv.second;
            }
        }

        localMap[labels[source]]++;
        ans[source] = localMap[labels[source]];
        return localMap;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> graph(n);
        vector<bool> vis(n, false);
        vector<int> ans(n, 0);

        for(auto edge: edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        solve(0, n, graph, labels, vis, ans);
        return ans;
    }
};