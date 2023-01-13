/*
Problem Title: 1519 - Number of Nodes in the Sub-Tree With the Same Label
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label
Submission Url: https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/submissions/876479593
*/

class Solution {
public:

    unordered_map<char, int> solve(int source, int n, vector<vector<int>>& graph, string& labels, vector<bool>& vis, vector<int>& ans) {

        unordered_map<char, int> lmp;

        if(source >= n) {
            return lmp;
        }
        if(vis[source]){
            return lmp;
        }
        vis[source] = true;

        cout<<"For node: "<<source<<endl;


        int count  = 0;

        for(int i=0; i < graph[source].size(); i++){
            int newSource = graph[source][i];
            if(vis[newSource]){
                continue;
            }

            auto lmp2 = solve(newSource, n, graph, labels, vis, ans);
            
            for(auto kv : lmp2){
                lmp[kv.first] += kv.second;
            }


        }

        lmp[labels[source]]++;
        print(lmp);
        
        cout<<source<<" ==  "<<lmp[labels[source]]<<endl;

        ans[source] = lmp[labels[source]];
        return lmp;

    }

    void print(unordered_map<char, int> mp){
        for(auto kv : mp){
            cout<<kv.first<<" - "<<kv.second<<endl;
        }
        cout<<endl;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> graph(n);
        vector<bool> vis(n, false);
        vector<int> ans(n, 0);

        for(auto edge: edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        solve(0, n, graph, labels, vis, ans);

        return ans;
    }
};