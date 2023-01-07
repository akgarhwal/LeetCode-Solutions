/*
Problem Title: 871 - Minimum Number of Refueling Stops
Lang: C++
Runtime: 23 ms
Memory: 16.1 MB
Problem Url: https://leetcode.com/problems/minimum-number-of-refueling-stops
Submission Url: https://leetcode.com/problems/minimum-number-of-refueling-stops/submissions/778542996
*/

class Solution {
public:
    int minRefuelStops(int target, int fuel, vector<vector<int>>& stations) {
        int ans = 0;
        priority_queue<int> pq;
        
        for(int i = 0; i < stations.size();i++){
            
            while(fuel < stations[i][0]){
                
                if(pq.empty()){
                    return -1;
                }
                
                fuel += pq.top(); pq.pop();
                ans += 1;
            }
            
            pq.push(stations[i][1]);
        }
        
        while( fuel < target){
            if(pq.empty()){
                return -1;
            }
            fuel += pq.top(); pq.pop();
            ans += 1;
        }
        return ans;
    }
};