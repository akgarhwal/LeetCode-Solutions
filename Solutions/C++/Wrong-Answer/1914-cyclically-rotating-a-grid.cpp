/*
Problem Title: 1914 - Cyclically Rotating a Grid
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/cyclically-rotating-a-grid
Submission Url: https://leetcode.com/problems/cyclically-rotating-a-grid/submissions/513737588
*/

class Solution {
public:
    int R = 4;
    int C = 4;
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        
        int r = grid.size();
        int c = grid[0].size();
        
        vector<int> mx;
        while( r > 0 and c > 0){
            mx.push_back((r+r+c+c-4));
            r-=2;
            c-=2;
        }
        int nk = mx[0];
        if(mx.size() > 2){
            for(int i = 1; i < mx.size(); i++){
                nk = __gcd(nk, mx[i]);
            }
        }
        
        cout<<k%(grid.size() + grid.size() + grid[0].size() + grid[0].size() - 4)<<endl;
        cout<<k%nk<<endl;
        cout<<nk<<endl;
        k = k %nk;
        while(k--){
            
            rotate(grid, grid.size(), grid[0].size());
        }
            
        return grid;
    }
    void rotate(vector<vector<int>> &grid, int r, int c){
        
        int x = 0, y = 0;
        
        while( x < r/2 and y < c/2){
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