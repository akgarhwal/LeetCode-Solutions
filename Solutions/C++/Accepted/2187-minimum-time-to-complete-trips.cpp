/*
Problem Title: 2187 - Minimum Time to Complete Trips
Lang: C++
Runtime: 632 ms
Memory: 94.4 MB
Problem Url: https://leetcode.com/problems/minimum-time-to-complete-trips
Submission Url: https://leetcode.com/problems/minimum-time-to-complete-trips/submissions/910799080
*/

class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long ans = 1000000000000000, lo = 0, hi = 1e15;

        while( lo <= hi) {
            long long mid = lo + ((hi - lo)>>1);
            
            unsigned long long count = 0LL;
            for(int i = 0; i < time.size(); i++) {
                count += (mid/(long long)time[i]);
            }

            if(count >= totalTrips) {
                hi = mid - 1;
                ans = min(ans, mid);
            } else {
                lo = mid + 1;
            }
        }

        return ans;
    }
};