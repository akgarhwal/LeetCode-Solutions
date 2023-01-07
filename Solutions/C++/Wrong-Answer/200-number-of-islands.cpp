/*
Problem Title: 200 - Number of Islands
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/number-of-islands
Submission Url: https://leetcode.com/problems/number-of-islands/submissions/320686883
*/

class Solution {
public:
        
   void explore(int start_x, int start_y, vector<vector<int>>& visited, int n, int m){
       
       int dir_x[] = {-1, 0, 1, 0};
       int dir_y[] = {0, 1, 0, -1};
       
        for(int i=0; i< 4; i++){
            int new_node_x = start_x + dir_x[i];
            int new_node_y = start_y + dir_y[i];
            
            if(new_node_x < 0 || new_node_x >= n || new_node_y < 0 || new_node_y >= m){
                continue;
            }
            
            if(visited[new_node_x][new_node_y] == 0){
                visited[new_node_x][new_node_y] = 1;
                explore(new_node_x, new_node_y, visited, n,m);
            }
        }       
   }     
    
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = (n == 0) ? 0 : grid[0].size();
        
        vector<vector<int>> visited(n, vector<int>(m,0));
        
        int ans = 0;
        
        for(int i = 0; i< n;i++){
            
            for(int j = 0; j< m; j++){
                
                if( visited[i][j] == 0){
                    
                    explore(i,j, visited, n, m);
                    
                    ans++;
                    
                }
                
                
            }
            
        }
        
        return ans;
    }
};