/*
Problem Title: 1701 - Average Waiting Time
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/average-waiting-time
Submission Url: https://leetcode.com/problems/average-waiting-time/submissions/434767019
*/

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double ans = 0.0;
        int tc = customers[0][0], tt = 0;
        for(auto cat : customers){
            if(tc < cat[0]) tc = cat[0];
            tt += (tc + cat[1] - cat[0]);
            tc = tc + cat[1];
        }
        return (double)tt/(double)customers.size();
    }
};