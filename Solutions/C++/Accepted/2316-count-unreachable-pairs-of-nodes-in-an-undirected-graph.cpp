/*
Problem Title: 2316 - Count Unreachable Pairs of Nodes in an Undirected Graph
Lang: C++
Runtime: 552 ms
Memory: 184.3 MB
Problem Url: https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph
Submission Url: https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/submissions/921567990
*/

class Solution {
public:

    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visit, int& count) {
        visit[node] = true;
        count += 1;

        for (int neighbor : adj[node]) {
            if (!visit[neighbor]) {
                dfs(neighbor, adj, visit, count);
            }
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visit(n);

        long long ans = 0LL;
        int count = 0;
        for(int i = 0; i < n; i++) {
            count = 0;
            if(!visit[i]) {
                dfs(i, adj, visit, count);
                ans += (count * 1LL * ((long long)n-count));
            }

        }


        return (ans>>1);
    }
};