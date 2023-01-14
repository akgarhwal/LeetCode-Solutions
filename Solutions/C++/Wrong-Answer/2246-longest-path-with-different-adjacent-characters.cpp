/*
Problem Title: 2246 - Longest Path With Different Adjacent Characters
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/longest-path-with-different-adjacent-characters
Submission Url: https://leetcode.com/problems/longest-path-with-different-adjacent-characters/submissions/877170329
*/

class Solution {
public:

    pair<int, char> solve(int root, vector<vector<int>>& graph, string& str, int& ans) {
        // cout<<"start - "<<root<<endl;
        if(root >= str.size()){
            return {0, ' '};
        }
        int length = 1;
        char ch = str[root];
        vector<int> path(26, 0);

        for(int i = 0 ; i < (int)graph[root].size(); i++) {
            auto res = solve(graph[root][i], graph, str, ans);

            if(res.second != ch){
                path[res.second - 'a'] = max(path[res.second - 'a'], res.first);
            }

            if(res.second != ch){
                length = max(length, res.first + 1);
            }
        }

        ans = max(ans, length);

        for(int i = 0 ; i < 26; i++) {
            for(int j = i+1; j < 26; j++) {
                if(path[j] > 0 and path[i] > 0 and ch != char(i+'a') and ch != char(j + 'a')){                
                    ans = max(ans, path[i]+path[j]+1);
                }
            }
        }
        cout<<"Node: "<<root<<endl;
        for(int i=0;i<26;i++){
            if(path[i] > 0){
                cout<<(char(i+'a'))<<" - "<<path[i]<<endl;
            }
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