/*
Problem Title: 2477 - Minimum Fuel Cost to Report to the Capital
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital
Submission Url: https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/submissions/896238496
*/

class Solution {
public:

    int solve(int source, vector<vector<int>>& adj, int& seats, vector<bool>& vis, int& ans) {
        if(vis[source]){
            return 0;
        }
        if(adj[source].size() == 1) {
            return 1;
        }
        vis[source] = true;
        int count = 0;
        for(int x = 0; x< adj[source].size(); x++) {
            if(!vis[adj[source][x]]) {
                int temp = solve(adj[source][x], adj, seats, vis, ans);
                ans += ceil(((double)temp)/seats);
                count += temp;
            }
        }
        count += 1;
        // cout<<"Source: "<<source<<" - "<<count<<endl; 
        return count;
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        vector<vector<int>> adj(n);
        vector<bool> vis(n, false);

        for(auto road : roads) {
            adj[road[0]].push_back(road[1]);
            adj[road[1]].push_back(road[0]);
        }
        int ans = 0;
        
        solve(0, adj, seats, vis, ans);
        // cout<<"Ans : "<<ans<<endl;
        return ans;
    }
};