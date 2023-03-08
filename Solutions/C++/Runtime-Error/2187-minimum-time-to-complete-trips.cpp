/*
Problem Title: 2187 - Minimum Time to Complete Trips
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/minimum-time-to-complete-trips
Submission Url: https://leetcode.com/problems/minimum-time-to-complete-trips/submissions/910797715
*/

class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long ans = 1e15, lo = 0, hi = 1e15;

        while( lo <= hi) {
            long long mid = lo + ((hi - lo)>>1);
            
            long long count = 0;
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