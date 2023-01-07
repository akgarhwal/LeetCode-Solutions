/*
Problem Title: 1220 - Count Vowels Permutation
Lang: C++
Runtime: 143 ms
Memory: 33.4 MB
Problem Url: https://leetcode.com/problems/count-vowels-permutation
Submission Url: https://leetcode.com/problems/count-vowels-permutation/submissions/767103272
*/

class Solution {
public:
    int M = 1000000007;

    int countVowelPermutation(int n) {
        if(n==1){
            return 5;
        }
        vector<vector<int>> dp(n+1, vector<int>(5, -1));
        
        map<int, vector<int>> mp;
        mp[0].push_back(1);
        mp[1].push_back(0);
        mp[1].push_back(2);
        mp[2].push_back(0);
        mp[2].push_back(1);
        mp[2].push_back(3);
        mp[2].push_back(4);
        mp[3].push_back(2);
        mp[3].push_back(4);
        mp[4].push_back(0);
        
        long ans =  (solve(0, n, dp, mp) % M + solve(1, n, dp, mp) % M + solve(2, n, dp, mp) % M + solve(3, n, dp, mp) % M + solve(4, n, dp, mp) % M) % M;
        return ans;
    }
    
    long solve(int vow, int n, vector<vector<int>> &dp, map<int, vector<int>> &mp){
        
        if(n == 2){
            vector<int> ans(5);
            ans[0] = 1;
            ans[1] = 2;
            ans[2] = 4;
            ans[3] = 2;
            ans[4] = 1;
            return ans[vow];
        }
        
        if(dp[n][vow] != -1){
            return dp[n][vow];
        }
        long ans = 0;
        
        for(int nv : mp[vow]){
            ans = (ans + solve(nv, n-1, dp, mp)) % M;
        }
        
        return dp[n][vow] = ans % M;
    }
};