/*
Problem Title: 2136 - Earliest Possible Day of Full Bloom
Lang: C++
Runtime: 269 ms
Memory: 158.7 MB
Problem Url: https://leetcode.com/problems/earliest-possible-day-of-full-bloom
Submission Url: https://leetcode.com/problems/earliest-possible-day-of-full-bloom/submissions/921353522
*/

class Solution {
public:

    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        
        vector<pair<int, int>> times(plantTime.size());
        for(int i = 0; i < times.size(); i++ ) {
            times[i] = {plantTime[i], growTime[i]};
        }

        sort(times.begin(), times.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        });

        int days = 0, pastPlantTime = 0;

        for(int i = 0; i < times.size(); i++) {
            pastPlantTime += times[i].first;
            days = max(days, pastPlantTime + times[i].second);
        }

        return days;
    }
};