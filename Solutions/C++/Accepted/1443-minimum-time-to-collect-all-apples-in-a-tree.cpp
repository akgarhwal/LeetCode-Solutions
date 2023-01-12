/*
Problem Title: 1443 - Minimum Time to Collect All Apples in a Tree
Lang: C++
Runtime: 204 ms
Memory: 64.9 MB
Problem Url: https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree
Submission Url: https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/submissions/875836090
*/

class Solution {
public:

    int solve(int startTime, int source, vector<vector<int>>& graph, vector<bool>& hasApple, int n, vector<bool>& visited) {
        if(source >= n){
            return 0;
        }
        
        if(visited[source]){
            return 0;
        }
        visited[source] = true;

        int totalTime = startTime;
        for(int i = 0; i < graph[source].size(); i++){
            if(!visited[graph[source][i]]){
                totalTime = solve( totalTime + 1, graph[source][i], graph, hasApple, n, visited);
            }
        }

        if(source == 0){
            return totalTime;
        }
        if(totalTime-startTime == 0 and hasApple[source]){
            return startTime + 1;
        }
        if(totalTime-startTime == 0) {
            return totalTime - 1;
        }
        return totalTime == 0 ? totalTime : totalTime +1 ;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> graph(n);
        vector<bool> visited(n, false);
        for(auto edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        return solve(0, 0, graph, hasApple, n, visited);
    }
};