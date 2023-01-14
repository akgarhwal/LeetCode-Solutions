/*
Problem Title: 2246 - Longest Path With Different Adjacent Characters
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/longest-path-with-different-adjacent-characters
Submission Url: https://leetcode.com/problems/longest-path-with-different-adjacent-characters/submissions/877148917
*/

class Solution {
public:

    pair<int, char> solve(int root, vector<vector<int>>& graph, string& str) {
        if(root >= str.size()){
            return {0, ' '};
        }

        int length = 1;
        char ch = str[root];

        for(int i = 0 ; i < graph[root].size(); i++) {

            auto res = solve(graph[root][i], graph, str);

            if(res.second != ch){
                length = max(length, res.first + 1);
            }
        }

        return {length, ch};
    }

    int longestPath(vector<int>& parent, string s) {
        vector<vector<int>> graph(parent.size());

        for(int i = 0; i < parent.size(); i++) {
            if(parent[i] != -1) {
                graph[i].push_back(parent[i]);
                graph[parent[i]].push_back(i);
            }
        }
        cout<<"Start"<<endl;
        auto ans = solve(0, graph, s);
        return ans.first;
    }
};