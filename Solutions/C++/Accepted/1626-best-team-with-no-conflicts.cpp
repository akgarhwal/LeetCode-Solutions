/*
Problem Title: 1626 - Best Team With No Conflicts
Lang: C++
Runtime: 527 ms
Memory: 133.6 MB
Problem Url: https://leetcode.com/problems/best-team-with-no-conflicts
Submission Url: https://leetcode.com/problems/best-team-with-no-conflicts/submissions/888772475
*/

class Solution {
public:

    int solve(vector<vector<int>>& dp, vector<pair<int, int>>& ageScorePair, int prev, int index)    {
        if (index >= ageScorePair.size()) {
            return 0;
        }
        
        if (dp[prev + 1][index] != INT_MIN) {
            return dp[prev + 1][index];
        }

        if (prev == -1 || ageScorePair[index].second >= ageScorePair[prev].second) {
            return dp[prev + 1][index] = max(
                solve(dp, ageScorePair, prev, index + 1), 
                ageScorePair[index].second + solve(dp, ageScorePair, index, index + 1)
            );
        }
        
        return dp[prev + 1][index] = solve(dp, ageScorePair, prev, index + 1);
    }

    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> vi;
        for(int i=0; i < scores.size(); i++) {
            vi.push_back({ages[i], scores[i]});
        }
        sort(vi.begin(), vi.end(), [](pair<int,int> p1, pair<int,int> p2) {
            if(p1.first != p2.first) {
                return p1.first <= p2.first;
            }
            return p1.second <= p2.second;
        });

        vector<vector<int>> dp(ages.size(), vector<int>(ages.size(), INT_MIN));
        return solve(dp, vi, -1, 0);
    }
};