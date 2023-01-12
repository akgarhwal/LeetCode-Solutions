/*
Problem Title: 1443 - Minimum Time to Collect All Apples in a Tree
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree
Submission Url: https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/submissions/875820364
*/

class Solution {
public:

    int solve(int time, int source, vector<vector<int>>& graph, vector<bool>& hasApple, int n) {
        if(source >= n){
            return 0;
        }

        int totalTime = time;
        for(int i = 0; i < graph[source].size(); i++){
            int res = solve( totalTime + 1, graph[source][i], graph, hasApple, n);
            totalTime = res;
        }

        if(source == 0){
            return totalTime;
        }

        if(totalTime-time == 0 and hasApple[source]){
            return time + 1;
        }
        if(totalTime-time == 0) {
            return totalTime - 1;
        }

        return totalTime == 0 ? totalTime : totalTime +1 ;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> graph(n);
        for(auto edge : edges){
            graph[edge[0]].push_back(edge[1]);
            // graph[edge[1]].push_back(edge[0]);
        }

        return solve(0, 0, graph, hasApple, n);
    }
};