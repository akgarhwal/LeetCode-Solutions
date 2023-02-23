/*
Problem Title: 1011 - Capacity To Ship Packages Within D Days
Lang: C++
Runtime: 49 ms
Memory: 26 MB
Problem Url: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days
Submission Url: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/submissions/902656409
*/

class Solution {
public:
    
    bool isShipped(vector<int>& weights, int days, int capacity) {
        int dayCounter = 0, currentLoad = 0;
        
        for(int w : weights) {
            if(w > capacity) {
                return false;
            }
            if(currentLoad + w <= capacity) {
                currentLoad += w;
            } else {
                dayCounter += 1;
                currentLoad = w;
            }
        }
        if(currentLoad > 0) {
            dayCounter += 1;
        }
        
        return dayCounter <= days;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int N = weights.size();
        int ans = INT_MAX;
        int lo = 0, hi = 300000000;
        
        while(lo <= hi) {
            int mid = lo + (hi-lo)/2;
            
            if(isShipped(weights, days, mid)) {
                ans = min(ans, mid);
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        
        return ans;       
    }
};