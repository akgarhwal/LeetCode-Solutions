/* Question: Max Area of Island
 * Lang: cpp
 * Runtime: 26 ms
 * Memory: 23.8 MB
 * Question Url: https://leetcode.com/problems/max-area-of-island
 * Submission Url:
 * https://leetcode.com/problems/max-area-of-island/submissions/747357328
 */

class Solution {
public:
  bool isInsideGrid(int i, int j, int n, int m) {
    if (i < 0 or j < 0 or i >= n or j >= m) {
      return false;
    }
    return true;
  }
  void dfs(vector<vector<int>> &grid, vector<vector<bool>> &vis, int i, int j,
           int &count) {
    count++;
    vis[i][j] = true;

    int X[] = {0, 1, 0, -1};
    int Y[] = {-1, 0, 1, 0};
    for (int a = 0; a < 4; a++) {
      int x = i + X[a];
      int y = j + Y[a];
      if (isInsideGrid(x, y, grid.size(), grid[0].size()) and
          grid[x][y] == 1 and vis[x][y] == false) {
        dfs(grid, vis, x, y, count);
      }
    }
  }
  int maxAreaOfIsland(vector<vector<int>> &grid) {
    int ans = 0;

    vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), 0));

    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < (int)grid[0].size(); j++) {

        if (grid[i][j] == 1 and vis[i][j] == 0) {

          int count = 0;
          dfs(grid, vis, i, j, count);
          ans = max(ans, count);
        }
      }
    }
    return ans;
  }
};
