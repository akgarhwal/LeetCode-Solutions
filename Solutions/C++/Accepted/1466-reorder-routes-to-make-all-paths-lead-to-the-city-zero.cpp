/*
Problem Title: 1466 - Reorder Routes to Make All Paths Lead to the City Zero
Lang: C++
Runtime: 503 ms
Memory: 126.5 MB
Problem Url: https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero
Submission Url: https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/submissions/921013680
*/

class Solution {
public:

    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visit, set<pair<int, int>>& edges, int& ans) {
        visit[node] = true;
        for (int neighbor : adj[node]) {
            if (!visit[neighbor]) {

                if(edges.find({node, neighbor}) != edges.end()) {
                    ans += 1;
                }

                dfs(neighbor, adj, visit, edges, ans);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {

        set<pair<int, int>> edges;

        vector<vector<int>> adj(n);
        for (auto& connection : connections) {
            edges.insert({connection[0], connection[1]});

            adj[connection[0]].push_back(connection[1]);
            adj[connection[1]].push_back(connection[0]);
        }

        int answer = 0;
        vector<bool> visit(n);

        dfs(0, adj, visit, edges, answer);

        return answer;
    }
};