/* Question: Unique Paths III
 * Lang: cpp
 * Runtime: 6 ms
 * Memory: 7.1 MB
 * Question Url: https://leetcode.com/problems/unique-paths-iii
 * Submission Url:
 * https://leetcode.com/problems/unique-paths-iii/submissions/868506086
 */

class Solution {
public:
  int R[4] = {-1, 0, 1, 0};
  int C[4] = {0, 1, 0, -1};

  bool canWalk(int x, int y, vector<vector<int>> &grid) {
    if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size()) {
      return false;
    }
    if (grid[x][y] != -1 and grid[x][y] != 5) {
      return true;
    }
    return false;
  }

  vector<pair<int, int>> path;

  // void printPath(){
  // for(pair<int,int> pi : path){
  // cout<<" ("<<pi.first<<", "<<pi.second<<") ";
  // }
  // cout<<endl;
  // }

  void solve(int x, int y, vector<vector<int>> &grid, int &pathLen,
             int curPathLen, int &ans) {
    // cout<<curPathLen<<" "<<grid[x][y]<<" ";
    // printPath();

    for (int d = 0; d < 4; d++) {
      int nx = x + R[d];
      int ny = y + C[d];

      if (canWalk(nx, ny, grid)) {

        if (curPathLen + 1 == pathLen && grid[nx][ny] == 2) {
          ans += 1;
          continue;
        }

        // path.push_back({nx,ny});

        int temp = grid[nx][ny];
        grid[nx][ny] = 5;
        solve(nx, ny, grid, pathLen, curPathLen + 1, ans);
        grid[nx][ny] = temp;

        // path.pop_back();
      }
    }
  }
  int uniquePathsIII(vector<vector<int>> &grid) {
    int x, y, ans = 0, pathLen = 0;
    int curPathLen = 0;
    // path.clear();

    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == 1) {
          x = i;
          y = j;
          grid[x][y] = 5; // 5 means already walk over this grid.
        }
        if (grid[i][j] == 0) {
          pathLen += 1;
        }
      }
    }
    pathLen += 1;
    // path.push_back({x,y});
    solve(x, y, grid, pathLen, curPathLen, ans);

    return ans;
  }
};
