/*
Problem Title: 1701 - Average Waiting Time
Lang: C++
Runtime: 664 ms
Memory: 83.2 MB
Problem Url: https://leetcode.com/problems/average-waiting-time
Submission Url: https://leetcode.com/problems/average-waiting-time/submissions/434769262
*/

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double ans = 0.0;
        long tc = customers[0][0], tt = 0;
        for(auto cat : customers){
            if(tc < (long)cat[0]) tc = (long)cat[0];
            tt += (tc + (long)cat[1] - (long)cat[0]);
            tc = tc + (long)cat[1];
        }
        return (double)tt/(double)customers.size();
    }
};