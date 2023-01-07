/*
Problem Title: 1334 - Find the City With the Smallest Number of Neighbors at a Threshold Distance
Lang: C++
Runtime: 68 ms
Memory: 12.6 MB
Problem Url: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance
Submission Url: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/submissions/487300509
*/

/*
 * @lc app=leetcode id=1334 lang=cpp
 *
 * [1334] Find the City With the Smallest Number of Neighbors at a Threshold Distance
 */

// @lc code=start
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> mat(n,vector<int>(n, 1e7));

        for(auto edge : edges) {
            mat[edge[0]][edge[1]] = edge[2];
            mat[edge[1]][edge[0]] = edge[2];
        }
        for(int k = 0; k < n; k++) {

            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(i!=j) {
                        if(k != i  and k != j)
                            // i - j  => i - k  and k - j
                            mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                    }
                }
            }
        }
        int ans = 0, cityCount = INT_MAX;
        for(int i = 0; i < n; i++) {
            int count=0;
            for(int j = 0; j < n; j++) {
                if(mat[i][j] <= distanceThreshold) {
                    count++;
                }
            }
            if(count <= cityCount){
                ans = i;
                cityCount = count;
            }
        }

        return ans;
    }
};
// @lc code=end

