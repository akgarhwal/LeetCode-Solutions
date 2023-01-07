/*
Problem Title: 1232 - Check If It Is a Straight Line
Lang: C++
Runtime: 20 ms
Memory: 10.3 MB
Problem Url: https://leetcode.com/problems/check-if-it-is-a-straight-line
Submission Url: https://leetcode.com/problems/check-if-it-is-a-straight-line/submissions/336296644
*/

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
       
        bool res = true;
        auto p1 = coordinates[0];
        auto p2 = coordinates[1];
        
        int slope_x = (p2[1] - p1[1]), slope_y = (p2[0] - p1[0]);
        
        for(int i = 2; i< coordinates.size();i++){
            auto p = coordinates[i];
            int slope2_x = (p1[1] - p[1]), slope2_y = (p1[0] - p[0]);
            if(slope2_x*slope_y != slope2_y*slope_x){
                res = false;
                break;
            }
        }
        return res;        
    }
};