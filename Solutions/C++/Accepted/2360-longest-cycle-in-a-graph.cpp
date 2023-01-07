/*
Problem Title: 2360 - Longest Cycle in a Graph
Lang: C++
Runtime: 582 ms
Memory: 135.4 MB
Problem Url: https://leetcode.com/problems/longest-cycle-in-a-graph
Submission Url: https://leetcode.com/problems/longest-cycle-in-a-graph/submissions/765040994
*/

class Solution {
public:
    void dfs(int s, vector<int>& edges, vector<bool>& visit, vector<int>& path, int &ans) {
        if(s == -1) {
            return;
        }
        
        if (visit[s]) {
            
            int pathIndex = -1;
            for(int i=0; i < path.size(); i++){
                if(path[i] == s){
                    pathIndex = i;
                    break;
                }
            }
            if(pathIndex == -1){
                return;
            }
            ans = max(ans, int(path.size()-pathIndex) );
            return;
        }
        path.push_back(s);
        visit[s] = true;
        dfs(edges[s], edges, visit, path, ans);
    }
    
    int longestCycle(vector<int>& edges) {
        
        int ans = -1;
        vector<bool> visit(edges.size(), false);
        
        for(int i = 0; i < edges.size(); i++){
            vector<int> path;
            if(!visit[i]) {
                dfs(i, edges, visit, path, ans);
            }
        }
        
        return ans;
    }
};