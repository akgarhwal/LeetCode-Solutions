/*
Problem Title: 2658 - Maximum Number of Fish in a Grid
Lang: C++
Runtime: 167 ms
Memory: 112.2 MB
Problem Url: https://leetcode.com/problems/maximum-number-of-fish-in-a-grid
Submission Url: https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/submissions/942972043
*/

class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int maxFish = 0;
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        vector<vector<bool>> visit(m, vector<bool>(n, false));
        
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
                if (grid[i][j] > 0 and visit[i][j] == false) {
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    int fishCaught = 0;
                    while (!q.empty()) {
                        int r = q.front().first;
                        int c = q.front().second;
                        q.pop();
                        
                        visit[r][c] = true;
                        
                        if (grid[r][c] > 0) {
                            fishCaught += grid[r][c];
                            grid[r][c] = 0;
                        }
                        for (auto& move : moves) {
                            int newR = r + move[0];
                            int newC = c + move[1];
                            if (newR >= 0 && newR < m && newC >= 0 && newC < n && grid[newR][newC] > 0) {
                                q.push({newR, newC});
                            }
                        }
                    }
                    maxFish = max(maxFish, fishCaught);
                }
            }
        }

        return maxFish;
    }
};