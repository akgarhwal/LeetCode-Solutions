/*
Problem Title: 149 - Max Points on a Line
Lang: C++
Runtime: 32 ms
Memory: 13.3 MB
Problem Url: https://leetcode.com/problems/max-points-on-a-line
Submission Url: https://leetcode.com/problems/max-points-on-a-line/submissions/873684913
*/

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans = 0;

        for(int i = 0; i < points.size(); i++) {
            int count = 0;
            unordered_map<double, int> ht;
            for(int j = i+1; j < points.size(); j++) {
                double slope;
                if( (points[j][0] - points[i][0]) != 0){
                    slope = (double)(points[j][1] - points[i][1]) / (points[j][0] - points[i][0]);
                }
                else{
                    slope = 1e7;
                }
                 ht[slope] += 1;
                count = max(count, ht[slope]);
            }
            ans = max(count + 1, ans);
        }
        return ans;
    }
};