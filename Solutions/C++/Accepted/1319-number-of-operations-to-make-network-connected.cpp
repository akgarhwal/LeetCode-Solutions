/*
Problem Title: 1319 - Number of Operations to Make Network Connected
Lang: C++
Runtime: 142 ms
Memory: 51.6 MB
Problem Url: https://leetcode.com/problems/number-of-operations-to-make-network-connected
Submission Url: https://leetcode.com/problems/number-of-operations-to-make-network-connected/submissions/920427645
*/

class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visit) {
        visit[node] = true;
        for (int neighbor : adj[node]) {
            if (!visit[neighbor]) {
                dfs(neighbor, adj, visit);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) {
            return -1;
        }

        vector<vector<int>> adj(n);
        for (auto& connection : connections) {
            adj[connection[0]].push_back(connection[1]);
            adj[connection[1]].push_back(connection[0]);
        }

        int numberOfConnectedComponents = 0;
        vector<bool> visit(n);
        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                numberOfConnectedComponents++;
                dfs(i, adj, visit);
            }
        }

        return numberOfConnectedComponents - 1;
    }
};