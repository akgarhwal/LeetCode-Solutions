/*
Problem Title: 2092 - Find All People With Secret
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/find-all-people-with-secret
Submission Url: https://leetcode.com/problems/find-all-people-with-secret/submissions/593773862
*/

class Solution {
public:
    
    void dfs(int s, unordered_map<int, vector<int>> &adj, unordered_set<int> &vis, bool &hasSec, unordered_set<int> &vis2, vector<bool> &sec) {
        vis2.insert(s);
        if(sec[s]){
            hasSec = true;
        }
        for(int x : adj[s]){
            // cout<<s<<" can go to "<<x<<endl;
            if(vis.find(x) == vis.end()){
                vis.insert(x);
                dfs(x, adj, vis, hasSec, vis2, sec);
            }
        }
    }
    
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        
        vector<bool> sec(n, false);
        
        map<int, vector<pair<int,int>>> mp;
        
        for(auto m : meetings) {
            mp[m[2]].push_back({m[0], m[1]});
        }
        
        
        sec[0] = sec[firstPerson] = true;
        
        for(auto ele : mp){
            
            vector<pair<int,int>> edges = ele.second;
            
            unordered_set<int> vis;
            
            unordered_map<int, vector<int>> adj;
            
            for(auto x : edges){
                adj[x.first].push_back(x.second);
                adj[x.second].push_back(x.first);
            }
            
            for(auto x : adj){
                if(vis.find(x.first) == vis.end()){
                    bool hasSec = false;
                    unordered_set<int> vis2;
                    dfs(x.first, adj, vis, hasSec, vis2, sec);
                    // cout<<x.first<<" => "<<hasSec<<endl;
                    if(hasSec){
                        for(int z : vis2){
                            sec[z] = true;
                        }
                    }
                }
            }
            
        }
        
        vector<int> ans;
        
        for(int i =0; i < sec.size();i++){
            if(sec[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};