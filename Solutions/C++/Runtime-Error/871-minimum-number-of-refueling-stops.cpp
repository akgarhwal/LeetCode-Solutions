/*
Problem Title: 871 - Minimum Number of Refueling Stops
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/minimum-number-of-refueling-stops
Submission Url: https://leetcode.com/problems/minimum-number-of-refueling-stops/submissions/506733830
*/

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        unordered_map<int,int> dp;
        int ans = solve(0, target, startFuel, stations, 0, dp);
        return ans == INT_MAX ? -1 : ans;
    }
    int solve(int pos, int target, int fuel, vector<vector<int>>& stations, int ind, unordered_map<int,int> &dp){
        
        
        cout<<pos<<" , "<<fuel<<" , "<<ind<<endl;
        
        
        if(pos+fuel >= target){
            cout<<ind<<"  Reached  "<<0<<endl;
            return 0;
        }
        int ans = INT_MAX;
    
        if(ind >= stations.size()){
            cout<<ind<<"  inf_OFO  "<<(pos + fuel >= target ? 0 : INT_MAX)<<endl;
            return dp[pos] =  (pos + fuel >= target ? 0 : INT_MAX);
        }
        
        vector<int> station = stations[ind];
        
        int dist = station[0] - pos;
        
        if( fuel - dist < 0){
            cout<<ind<<"  dp_NP  "<<ans<<endl;
            return dp[pos] = ans;
        }
        
        if(dp.find(pos) != dp.end()){
             cout<<ind<<"  dp  "<<dp[pos]<<endl;
            return dp[pos];
        }
        
        ans = min(ans, solve(station[0], target, fuel - dist + station[1], stations, ind+1, dp)+1);
        
        ans = min(ans, solve(station[0], target, fuel - dist, stations, ind+1, dp));
        
        cout<<ind<<" - "<<ans<<endl;
        
        return dp[pos] = ans;
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