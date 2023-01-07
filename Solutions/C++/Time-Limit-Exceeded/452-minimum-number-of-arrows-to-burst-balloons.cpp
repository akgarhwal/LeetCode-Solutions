/*
Problem Title: 452 - Minimum Number of Arrows to Burst Balloons
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons
Submission Url: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/submissions/872084574
*/

class Solution {
public:
    static bool sortBy(vector<int> first, vector<int> second){
        if(first[1] < second[1]) {
            return true;
        }
        if(first[1] > second[1]) {
            return false;
        }
        // if(first[1] == second[1] and first[0] < second[0]){
        //     return true;
        // }
        return first[0] <= second[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), sortBy);

        int ans = 0, sz = points.size();
        int last = INT_MIN;
        int i = 0;
        if(points[0][0] == last){
            i = 1;
            ans += 1;
            last = points[0][1];
        }
        for(; i < sz; i++) {
            if(points[i][0] > last) {
                ans += 1;
                last = points[i][1];
            }
        }
        return ans;
    }
};