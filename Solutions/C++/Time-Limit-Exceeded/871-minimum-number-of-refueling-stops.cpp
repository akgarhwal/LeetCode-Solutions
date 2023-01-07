/*
Problem Title: 871 - Minimum Number of Refueling Stops
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/minimum-number-of-refueling-stops
Submission Url: https://leetcode.com/problems/minimum-number-of-refueling-stops/submissions/506853700
*/

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        unordered_map<string,int> dp;
        int ans = solve(0, target, startFuel, stations, 0, dp);
        return ans > 500 ? -1 : ans;
    }
    int solve(int pos, int target, int fuel, vector<vector<int>>& stations, int ind, unordered_map<string,int> &dp){
        string key = to_string(pos) + "_" + to_string(fuel);
        
        if(pos+fuel >= target){
            return dp[key] = 0;
        }
        int ans = 1000;
        if(ind >= stations.size()){
            return dp[key] =  (pos + fuel >= target ? 0 : 1000);
        }
        
        vector<int> station = stations[ind];
        
        int dist = station[0] - pos;
        
        if( fuel - dist < 0){
            // cout<<ind<<"  dp_NP  "<<ans<<endl;
            return dp[key] = ans;
        }
        
        if(dp.find(key) != dp.end()){
            return dp[key];
        }
        
        ans = min(ans, solve(station[0], target, fuel - dist + station[1], stations, ind+1, dp)+1);
        
        ans = min(ans, solve(station[0], target, fuel - dist, stations, ind+1, dp));
        
        return dp[key] = ans;
    }
};

/*
1
1
[]
100
1
[[10,100]]
*/