/* Question: All Paths From Source to Target
 * Lang: cpp
 * Runtime: 10 ms
 * Memory: 10.7 MB
 * Question Url: https://leetcode.com/problems/all-paths-from-source-to-target
 * Submission Url:
 * https://leetcode.com/problems/all-paths-from-source-to-target/submissions/867868033
 */

class Solution {
public:
  void findAllPaths(int source, int target, vector<int> &path,
                    vector<vector<int>> &graph, vector<vector<int>> &ans) {
    // base case: if source is equal to target, add the path to the answer and
    // return
    if (source == target) {
      ans.push_back(path);
      return;
    }

    // iterate through all the adjacent nodes of source
    for (int x : graph[source]) {
      // add the node to the path
      path.push_back(x);

      // recursively call findAllPaths with x as source and target as target
      findAllPaths(x, target, path, graph, ans);

      // remove the node from the path after recursive call returns
      path.pop_back();
    }
  }

  vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {

    // create a 2D vector to store all paths from source to target
    vector<vector<int>> ans;

    // create a 1D vector to store current path from source to target
    vector<int> path;

    // add 0 (source) in the current path
    path.push_back(0);

    // call findAllPaths with 0 as source and size-1 as target
    findAllPaths(0, graph.size() - 1, path, graph, ans);

    return ans; // return all paths from source to target
  }
};
