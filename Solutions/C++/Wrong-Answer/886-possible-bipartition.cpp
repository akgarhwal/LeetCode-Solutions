/*
Problem Title: 886 - Possible Bipartition
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/possible-bipartition
Submission Url: https://leetcode.com/problems/possible-bipartition/submissions/345483124
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
            // if(tree[a].size() == 0){
            //     vector<int> temp;
            //     tree[a] = temp;
            // }
            tree[a].push_back(b);
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