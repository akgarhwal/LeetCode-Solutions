/*
Problem Title: 778 - Swim in Rising Water
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/swim-in-rising-water
Submission Url: https://leetcode.com/problems/swim-in-rising-water/submissions/510626080
*/

class Solution {
public:
    bool inLim(int i, int j, int N){
        if( i < 0 or j < 0 or i>= N or j >= N){
            return false;
        }
        return true;
    }
    int X[4] = {1,0,-1,0};
    int Y[4] = {0,1,0,-1};
    bool dfs(int i, int j, int t, vector<vector<int>>& grid, vector<vector<bool>>& vis){
        int N = grid.size();
        if( i == N-1 and j == N-1){
            return true;
        }
        bool ans = false;
        vis[i][j] = true;
        for(int x=0; x< 4; x++){
            int ni = X[x] + i, nj = Y[x] + j;
            if(inLim(ni, nj, N) and vis[ni][nj] == false and grid[ni][nj] <= t){
                ans = ans or dfs(ni,nj,t,grid,vis);
                if(ans){
                    return ans;
                }
            }
        }
        return ans;
    }
    
    bool isPath(int t, vector<vector<int>>& grid){
        int N = grid.size();
        vis.assign(N, vector<bool>(N, false));
        bool ans = dfs(0,0,t,grid,vis);
        return ans;
    }
    vector<vector<bool>> vis;
    int swimInWater(vector<vector<int>>& grid) {
        int N = grid.size();
        int lo = 1, hi = N*N-1;
        int ans = hi;
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            if(isPath(mid, grid) == true){
                ans = mid;
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        return ans;
    }
};