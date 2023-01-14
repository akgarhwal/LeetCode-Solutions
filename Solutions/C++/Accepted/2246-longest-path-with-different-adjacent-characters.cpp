/*
Problem Title: 2246 - Longest Path With Different Adjacent Characters
Lang: C++
Runtime: 674 ms
Memory: 213.2 MB
Problem Url: https://leetcode.com/problems/longest-path-with-different-adjacent-characters
Submission Url: https://leetcode.com/problems/longest-path-with-different-adjacent-characters/submissions/877187831
*/

class Solution {
public:
    pair<int, char> solve(int root, vector<vector<int>>& graph, string& str, int& ans) {
        if(root >= str.size()){
            return {0, ' '};
        }

        int length = 1;
        char ch = str[root];
        vector<int> path;

        for(int i = 0 ; i < (int)graph[root].size(); i++) {
            auto res = solve(graph[root][i], graph, str, ans);

            if(res.second != ch){
                path.push_back(res.first);
                
            }

            if(res.second != ch){
                length = max(length, res.first + 1);
            }
        }
        ans = max(ans, length);
        sort(path.begin(), path.end());

        if(path.size() >=2){
            ans = max(ans, path[path.size()-1] + 1 + path[path.size()-2]);
        }
        if(path.size() == 1){
            ans = max(ans, path[0] + 1);
        }
        
        return {length, ch};
    }

    int longestPath(vector<int>& parent, string s) {
        vector<vector<int>> graph(parent.size());

        for(int i = 0; i < parent.size(); i++) {
            if(parent[i] != -1) {
                graph[parent[i]].push_back(i);
            }
        }
        int ans = 0;
        solve(0, graph, s, ans);
        return ans;
    }
};