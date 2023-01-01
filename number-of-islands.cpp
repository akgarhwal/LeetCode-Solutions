/* Question: Number of Islands
 * Lang: cpp
 * Runtime: 37 ms
 * Memory: 13.4 MB
 * Question Url: https://leetcode.com/problems/number-of-islands
 * Submission Url:
 * https://leetcode.com/problems/number-of-islands/submissions/769887327
 */

class Solution {
public:
  void explore(int start_x, int start_y, vector<vector<int>> &visited,
               vector<vector<char>> &grid) {

    int dir_x[] = {-1, 0, 1, 0};
    int dir_y[] = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++) {
      int new_node_x = start_x + dir_x[i];
      int new_node_y = start_y + dir_y[i];

      if (new_node_x < 0 || new_node_x >= grid.size() || new_node_y < 0 ||
          new_node_y >= grid[0].size()) {
        continue;
      }

      if (visited[new_node_x][new_node_y] == 0 and
          grid[new_node_x][new_node_y] == '1') {
        visited[new_node_x][new_node_y] = 1;
        explore(new_node_x, new_node_y, visited, grid);
      }
    }
  }

  int numIslands(vector<vector<char>> &grid) {

    int n = grid.size();
    int m = (n == 0) ? 0 : grid[0].size();

    vector<vector<int>> visited(n, vector<int>(m, 0));

    int ans = 0;

    for (int i = 0; i < n; i++) {

      for (int j = 0; j < m; j++) {

        if (visited[i][j] == 0 && grid[i][j] == '1') {

          explore(i, j, visited, grid);

          ans++;
        }
      }
    }

    return ans;
  }
};
