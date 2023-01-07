/*
Problem Title: 684 - Redundant Connection
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/redundant-connection
Submission Url: https://leetcode.com/problems/redundant-connection/submissions/513283032
*/

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;
        vector<bool> vis(edges.size()+1, false);
        for(auto edge : edges){
            if(vis[edge[0]] and vis[edge[1]]){
                ans = edge;
                break;
            }
            vis[edge[0]] = true;
            vis[edge[1]] = true;
        }
        return ans;
    }
};