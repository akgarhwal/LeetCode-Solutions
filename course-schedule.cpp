/* Question: Course Schedule
 * Lang: cpp
 * Runtime: 44 ms
 * Memory: 13.2 MB
 * Question Url: https://leetcode.com/problems/course-schedule
 * Submission Url:
 * https://leetcode.com/problems/course-schedule/submissions/346378866
 */

class Solution {
public:
  void dfs(vector<int> &vis, int node, vector<vector<int>> &tree, int ci,
           bool &ans) {
    if (ans == false) {
      return;
    }
    vis[node] = ci;
    for (int i = 0; i < tree[node].size(); i++) {
      int nn = tree[node][i];
      if (vis[nn] == ci) {
        ans = false;
        return;
      }

      dfs(vis, nn, tree, ci, ans);
    }

    vis[node] = -1;
  }

  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    vector<int> vis(numCourses, 0);
    vector<vector<int>> tree(numCourses, vector<int>());

    for (int i = 0; i < prerequisites.size(); i++) {
      int a = prerequisites[i][0], b = prerequisites[i][1];
      tree[b].push_back(a);
    }

    bool ans = true;
    for (int i = 0; i < numCourses; i++) {

      if (vis[i] == 0) {
        dfs(vis, i, tree, i + 1, ans);
      }
    }
    return ans;
  }
};
