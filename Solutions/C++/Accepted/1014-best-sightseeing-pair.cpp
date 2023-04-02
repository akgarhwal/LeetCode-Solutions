/*
Problem Title: 1014 - Best Sightseeing Pair
Lang: C++
Runtime: 86 ms
Memory: 44.8 MB
Problem Url: https://leetcode.com/problems/best-sightseeing-pair
Submission Url: https://leetcode.com/problems/best-sightseeing-pair/submissions/925957604
*/

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        
        int ans = 0;
        priority_queue<int> pq;

        pq.push(values[0]);

        for(int i = 1; i < values.size(); i++) {

            ans = max(ans, pq.top() + values[i]-i);
            pq.push(values[i] + i);
        }

        return ans;
    }
};