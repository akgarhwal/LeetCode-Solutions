/*
Problem Title: 1162 - As Far from Land as Possible
Lang: C++
Runtime: 78 ms
Memory: 21.4 MB
Problem Url: https://leetcode.com/problems/as-far-from-land-as-possible
Submission Url: https://leetcode.com/problems/as-far-from-land-as-possible/submissions/895045528
*/

class Solution {
public:

    bool isInside(int x, int y, int n) {
        if(x < 0 or y < 0  or x >= n or y >= n) {
            return false;
        }
        return true;
    }

    int maxDistance(vector<vector<int>>& grid) {
        int X[] = {0, 1, 0, -1};
        int Y[] = {1, 0, -1, 0};

        int n = grid.size();
        queue<pair<pair<int,int>,int>> q;

        for(int i = 0; i < n; i++ ) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j]) {
                    q.push({{i,j}, 0});
                }
            }
        }
        if(q.size() == n*n) {
            return -1;
        }

        int ans = -1;
        while(!q.empty()) {

            auto ele =  q.front();
            q.pop();

            ans = max(ans, ele.second);

            for(int d = 0; d < 4; d++) {
                int newX = ele.first.first + X[d];
                int newY = ele.first.second + Y[d];

                if( isInside(newX, newY, n) && grid[newX][newY] == 0 ) {
                    grid[newX][newY] = ele.second + 1;
                    q.push({{newX, newY}, ele.second + 1});
                }
            }
        }

        return ans;
    }
};