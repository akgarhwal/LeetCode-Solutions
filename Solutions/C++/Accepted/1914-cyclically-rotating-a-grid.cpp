/*
Problem Title: 1914 - Cyclically Rotating a Grid
Lang: C++
Runtime: 60 ms
Memory: 12.6 MB
Problem Url: https://leetcode.com/problems/cyclically-rotating-a-grid
Submission Url: https://leetcode.com/problems/cyclically-rotating-a-grid/submissions/513744848
*/

class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        
        rotate(grid, grid.size(), grid[0].size(), k);
            
        return grid;
    }
    void rotate(vector<vector<int>> &grid, int r, int c, int k){
        
        int x = 0, y = 0;
        
        int R = r, C = c;
        
        while( x < r/2 and y < c/2){
            
            int nk =  k  % (R+R + C + C - 4);
            
            while(nk--){
            
                int bk1 = grid[x][y];
            
                //move first row
                for(int i = y+1 ; i < c-y; i++){
                    grid[x][i-1] = grid[x][i];
                }
                // move last col
                for(int i = x+1 ; i < r-x;i++){
                    grid[i-1][c-y-1] = grid[i][c-y-1];
                }
                // move last row
                for(int i = c-y-2; i >= y ;i--){
                    grid[r-x-1][i+1] = grid[r-x-1][i];
                }
                // omve first col
                for(int i = r-x-2 ; i >=x;i--){
                    grid[i+1][y] = grid[i][y];
                }
                grid[x+1][y] = bk1;
            }
            R-=2;
            C-=2;
            x++;
            y++;
        }
        
    }
    void print(vector<vector<int>> &grid){
        cout<<endl;
        for(int i =0 ; i < grid.size(); i++){
            for(int j = 0 ; j < grid[1].size();j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
    }

};