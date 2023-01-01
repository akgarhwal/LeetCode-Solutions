/* Question: Count Sub Islands
 * Lang: cpp
 * Runtime: 536 ms
 * Memory: 122.3 MB
 * Question Url: https://leetcode.com/problems/count-sub-islands
 * Submission Url:
 * https://leetcode.com/problems/count-sub-islands/submissions/510417599
 */

class Solution {
public:
  bool inLim(int i, int j, int R, int C) {
    if (i < 0 or j < 0 or i >= R or j >= C) {
      return false;
    }
    return true;
  }
  int X[4] = {1, 0, -1, 0};
  int Y[4] = {0, 1, 0, -1};
  void dfs(int i, int j, int k, vector<vector<int>> &vis,
           vector<vector<int>> &grid) {

    vis[i][j] = k;
    for (int x = 0; x < 4; x++) {
      int ni = X[x] + i;
      int nj = Y[x] + j;
      if (inLim(ni, nj, grid.size(), grid[0].size()) and vis[ni][nj] == 0 and
          grid[ni][nj] == 1) {
        dfs(ni, nj, k, vis, grid);
      }
    }
  }
  void dfs1(int i, int j, int k, vector<vector<int>> &vis,
            queue<pair<int, int>> &q, vector<vector<int>> &grid) {
    int X[] = {1, 0, -1, 0};
    int Y[] = {0, 1, 0, -1};
    vis[i][j] = k;
    q.push({i, j});
    for (int x = 0; x < 4; x++) {
      int ni = X[x] + i;
      int nj = Y[x] + j;
      if (inLim(ni, nj, grid.size(), grid[0].size()) and vis[ni][nj] == 0 and
          grid[ni][nj] == 1) {
        dfs1(ni, nj, k, vis, q, grid);
      }
    }
  }
  int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2) {
    vector<vector<int>> vis1(grid1.size(), vector<int>(grid1[0].size(), 0));
    vector<vector<int>> vis2(grid2.size(), vector<int>(grid2[0].size(), 0));

    int k = 1;
    for (int i = 0; i < grid1.size(); i++) {
      for (int j = 0; j < grid1[0].size(); j++) {
        if (vis1[i][j] == 0 and grid1[i][j] == 1) {
          dfs(i, j, k, vis1, grid1);
          k += 1;
        }
      }
    }
    int ans = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < grid2.size(); i++) {
      for (int j = 0; j < grid2[0].size(); j++) {
        if (vis2[i][j] == 0 and grid2[i][j] == 1) {
          dfs1(i, j, 1, vis2, q, grid2);
          int check = vis1[q.front().first][q.front().second];
          bool isSame = true;
          while (!q.empty()) {
            auto p = q.front();
            q.pop();
            if (vis1[p.first][p.second] != check) {
              isSame = false;
            }
          }
          if (isSame and check != 0) {
            ans++;
          }
        }
      }
    }
    return ans;
  }
};
