/*
Problem Title: 886 - Possible Bipartition
Lang: C++
Runtime: 388 ms
Memory: 64.5 MB
Problem Url: https://leetcode.com/problems/possible-bipartition
Submission Url: https://leetcode.com/problems/possible-bipartition/submissions/345485698
*/

class Solution {
public:
    void bfs(int node, vector<vector<int>>& dis, vector<int>& color, bool& ans){
        
        if(ans == false){
            return;
        }
        
        int nc = 1 - color[node];
        
        
        for(int i =0; i < dis[node].size();i++){
            
            int nn = dis[node][i];
            if(color[nn] == color[node]){
                ans = false;
                return;
            }
            
            if(color[nn] != -1){
                continue;
            }
            
            color[nn] = nc;
            
            bfs(nn, dis, color, ans);
            
        }
        
        
        
    }
    
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        
        vector<int> color(N+1, -1);
        bool ans = true;
        vector<vector<int>> tree(N+1, vector<int>());
        
        for(int i=0;i<dislikes.size();i++){
            int a = dislikes[i][0], b = dislikes[i][1];
            tree[a].push_back(b);
            tree[b].push_back(a);
        }
        
        for(int i = 1; i<= N ; i++){
            
            if(color[i] != -1){
                continue;
            }
            color[i] = 1;
            bfs(i, tree, color, ans);
        }
        
        return ans;
    }
};