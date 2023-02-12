/*
Problem Title: 1129 - Shortest Path with Alternating Colors
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/shortest-path-with-alternating-colors
Submission Url: https://leetcode.com/problems/shortest-path-with-alternating-colors/submissions/895661064
*/

class Solution {
public:

    int bfs(int source, int target, vector<vector<int>>& adjRed, vector<vector<int>>& adjBlue) {
        int ans = -1;
        queue<pair<int, pair<int,int>>> q;
        q.push({0, {0, 0}}); // 0 - Red, 1 - Blue
        q.push({0, {0, 1}});

        while(!q.empty()) {

            auto ele = q.front();
            q.pop();

            if(ele.first == target) {
                ans = ele.second.first;
                break;
            }

            if(ele.second.second == 0) {
                for(int i = 0; i < adjBlue[ele.first].size(); i++) {
                    q.push({adjBlue[ele.first][i], {ele.second.first+1, 1}});
                }
            } else {
                for(int i = 0; i < adjRed[ele.first].size(); i++) {
                    q.push({adjRed[ele.first][i], {ele.second.first+1, 0}});
                }
            }
        }

        return ans;
    }


    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> ans(n, -1);
        vector<vector<int>> adjRed(n);
        vector<vector<int>> adjBlue(n);

        for(vector<int> edge : redEdges) {
            adjRed[edge[0]].push_back(edge[1]);
        }
        for(auto edge : blueEdges) {
            adjBlue[edge[0]].push_back(edge[1]);
        }

        for(int i = 0; i < n; i++ ) {
            int distance = bfs(0, i, adjRed, adjBlue);
            ans[i] = distance;
        }


        return ans;
    }
};