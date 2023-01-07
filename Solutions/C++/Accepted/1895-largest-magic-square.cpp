/*
Problem Title: 1895 - Largest Magic Square
Lang: C++
Runtime: 520 ms
Memory: 9.2 MB
Problem Url: https://leetcode.com/problems/largest-magic-square
Submission Url: https://leetcode.com/problems/largest-magic-square/submissions/506840364
*/

class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int ans = 1; 
        int R = grid.size();
        int C = R == 0 ? 0. : grid[0].size(); 
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0 ; j < grid[i].size(); j++){
                for(int x = 2; x <= min(R-i, C - j); x++){
                    if(isMagic(x,i, j, R,C, grid)){
                        ans = max(ans, x);
                    }
                }
            }
        }
        return ans;
    }
    
    bool isMagic(int k, int i, int j, int R, int C, vector<vector<int>>& grid){
        
        int c_sum = 0;        
        for(int x = i; x < i+k; x++){
            c_sum += grid[x][j];
        }
        int cj = j+1;
        while(cj < j+k){
            int c_sum2 = 0;
            for(int x = i; x < i+k; x++){
                c_sum2 += grid[x][cj];
            }
            cj++;
            if(c_sum != c_sum2){
                return false;
            }
        }
        cj = i;
        while(cj < i+k){
            int c_sum2 = 0;
            for(int x = j; x < j+k; x++){
                c_sum2 += grid[cj][x];
            }
            cj++;
            if(c_sum != c_sum2){
                return false;
            }
        }
        
        
        int x = i, y = j;
        int sum_d1 = 0;
        while(x < i+k) {
            sum_d1 += grid[x][y];
            x++;
            y++;
        }
        int sum_d2=0;
        x = i; y = j+k-1;
        while(x < i+k){
            sum_d2 += grid[x][y];
            x++;
            y--;
        }
        
        if(sum_d1 != c_sum) return false;
        
         if(sum_d2 != c_sum) return false;
        
        return true;
        
    }
};