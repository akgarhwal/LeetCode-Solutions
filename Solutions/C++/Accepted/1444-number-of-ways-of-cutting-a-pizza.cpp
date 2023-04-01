/*
Problem Title: 1444 - Number of Ways of Cutting a Pizza
Lang: C++
Runtime: 79 ms
Memory: 23.7 MB
Problem Url: https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza
Submission Url: https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/submissions/925309189
*/

class Solution {
public:
    const int MOD = 1e9 + 7;
    
    int get(int i,int j,int x,int y, vector<vector<int>>& pref){
        int sum = 0;

        sum += pref[x][y];
        if(i) {
            sum-=pref[i-1][y];
        }
        if(j) {
            sum-=pref[x][j-1];
        }
        if(i && j) {
            sum+=pref[i-1][j-1];
        }

        return sum;
    }
    
    int dfs(int x, int y, vector<string> &a, int k, vector<vector<int>>& pref, vector<vector<vector<int>>>& dp, int n, int m) {
        if(k == 0) {
            if(get(x,y,n-1,m-1, pref)==0) {
                return 0;
            }

            return 1;
        }
        int &ans = dp[x][y][k];

        if(ans!=-1) {
            return ans;
        }

        ans=0;
        for(int i = x; i < n; i++) {

            if( get(x, y, i, m-1, pref) > 0 ) {
                ans += dfs(i+1, y, a, k-1, pref, dp, n, m);
                ans %= MOD;
            }
        }
        for(int j = y; j < m; j++){

            if( get(x, y, n-1, j, pref) > 0 ){
                ans += dfs(x, j+1, a, k-1, pref, dp, n, m);
                ans %= MOD;
            }
        }
        return ans;
    }
    
    int ways(vector<string>& a, int k) {
        int n = a.size(), m = a[0].size();
        vector<vector<int>> pref(n, vector<int>(m, 0));

        vector<vector<vector<int>>> dp(51, vector<vector<int>>(51, vector<int>(11, -1)));

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {

                pref[i][j] += (a[i][j] == 'A');

                if(i) {
                    pref[i][j] += pref[i-1][j];
                }
                if(j) {
                    pref[i][j] += pref[i][j-1];
                }
                if(i && j) {
                    pref[i][j] -= pref[i-1][j-1];
                }
            }
        }

        return dfs(0, 0, a, k-1, pref, dp, n, m); 
    }
};