/*
Problem Title: 983 - Minimum Cost For Tickets
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/minimum-cost-for-tickets
Submission Url: https://leetcode.com/problems/minimum-cost-for-tickets/submissions/486335292
*/

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366, 10000);

        dp[0] = 0;
        int i = 0;
        for(int day = 1; day <= 365; day++) {
            if(i < days.size() && day == days[i]) {
                i++;
                // 1 day
                if(day - 1 >= 0)
                    dp[day] = min(dp[day], dp[day - 1] + costs[0]);

                // 7 day
                if(day - 7 >= 0)
                    dp[day] = min(dp[day], dp[day - 7] + costs[1]);

                // 30 day
                if(day - 30 >= 0)
                    dp[day] = min(dp[day], dp[day - 30] + costs[2]);


            }
            else{

                dp[day] = dp[day-1];

            }
            

        }
        return dp[365];
    }
};