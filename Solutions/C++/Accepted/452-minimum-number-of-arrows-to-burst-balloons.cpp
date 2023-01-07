/*
Problem Title: 452 - Minimum Number of Arrows to Burst Balloons
Lang: C++
Runtime: 1038 ms
Memory: 89.8 MB
Problem Url: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons
Submission Url: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/submissions/872092219
*/

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());

        int ans = 1, sz = points.size();
        int first = points[0][0], last = points[0][1];
       
        for(int i = 1; i < sz; i++) {
            if(points[i][0] <= last) {
                first = max(first, points[i][0]);
                last = min(last, points[i][1]);
            } else {
                ans += 1;
                first = points[i][0];
                last = points[i][1];
            }
        }
        return ans;
    }
};