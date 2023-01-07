/*
Problem Title: 1690 - Stone Game VII
Lang: C++
Runtime: 628 ms
Memory: 389.8 MB
Problem Url: https://leetcode.com/problems/stone-game-vii
Submission Url: https://leetcode.com/problems/stone-game-vii/submissions/506326450
*/

class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        vector<int> sum;
        sum.push_back(stones[0]);
        for(int i = 1; i < stones.size();i++){
            sum.push_back(sum[i-1] + stones[i]);
        }
        vector<vector<pair<int,int>>> dp(1000, vector<pair<int,int>>(1000, {0,0}));
        pair<int,int> ans = solve(0,stones.size()-1, stones, 0, sum, dp);
        return ans.first - ans.second;
    }
    
    pair<int,int> solve(int i, int j, vector<int>& stones, int bob_turn, vector<int>& sum, vector<vector<pair<int,int>>> &dp){
        if(i == j){
            return {0,0};
        }
        pair<int,int> pi = dp[i][j];
        
        if(pi.first != 0){
            return pi;
        }
        
        pair<int,int> s1 = solve(i+1,j,stones, !bob_turn, sum, dp);
        
        pair<int,int> s2 = solve(i,j-1,stones, !bob_turn, sum, dp);
        
        int sum1 = sum[j] - sum[i], sum2 = sum[j-1] - (i-1 >= 0 ? sum[i-1] : 0);
        
        if(bob_turn){
            s1.second += sum1;
            s2.second += sum2;
            if(diff(s1) > diff(s2)){
                return dp[i][j] =s2;
            }
            return dp[i][j]=s1;
        }
        else{
            s1.first += sum1;
            s2.first += sum2;
            if(diff(s1) > diff(s2)){
                return dp[i][j] =s1;
            }
            return dp[i][j] = s2;
        }
        
    }
    int diff(pair<int,int> p){
        return (p.first - p.second);
    }
};