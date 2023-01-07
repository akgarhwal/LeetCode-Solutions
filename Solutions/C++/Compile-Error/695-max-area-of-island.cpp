/*
Problem Title: 695 - Max Area of Island
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/max-area-of-island
Submission Url: https://leetcode.com/problems/max-area-of-island/submissions/321720462
*/

class Solution {
public:
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    
    void explore(int st_x, int st_y, int& count, vector<vector<int>>& vis, vector<vector<int>>& grid){
        
        int n = grid.size();
        int m = grid.size() == 0 ? 0 : grid[0].size();
        
        vis[st_x][st_y] = 1;
        count += 1;
        
        for(int i = 0; i < 4; i++){
            
            int new_x = st_x + dx[i];
            int new_y = st_y + dy[i];
            
            if(new_x < 0 or new_x >= n or new_y < 0 or new_y >=m ){
                continue;
            }
            
            if(vis[new_x][new_y] == 0 and grid[new_x][new_y] == 1){
                
                explore(new_x, new_y, count, vis, grid);
                
            }
            
            
        }
        
        
    }
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid.size() == 0 ? 0 : grid[0].size();
        
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                
                if(vis[i][j] == 0 && grid[i][j] == 1){
                    
                    int count = 0;
                    explore(i, j, count, vis, grid);
                    ans = max(ans, count);
                }
                
            }
        }
        return ans;
    }
};