/*
Problem Title: 1828 - Queries on Number of Points Inside a Circle
Lang: C++
Runtime: 849 ms
Memory: 167.4 MB
Problem Url: https://leetcode.com/problems/queries-on-number-of-points-inside-a-circle
Submission Url: https://leetcode.com/problems/queries-on-number-of-points-inside-a-circle/submissions/881753779
*/

class Solution {
public:

    bool isPointInCircle(int pointX, int pointY, int centerX, int centerY, double radius) {
        double distance = sqrt(pow(pointX - centerX, 2) + pow(pointY - centerY, 2));
        return distance <= radius;
    }

    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans;
        for(auto query : queries) {
            int count = 0;
            for(auto point : points) {
                if(isPointInCircle(point[0], point[1], query[0], query[1], (double)query[2])) {
                    count += 1;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};