/*
Problem Title: 188 - Best Time to Buy and Sell Stock IV
Lang: C++
Runtime: 1205 ms
Memory: 12 MB
Problem Url: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv
Submission Url: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/submissions/795997413
*/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        vector<vector<int>> memo(prices.size()+1, vector<int>(k+1, -1));
        return recur(prices, 0, k, memo);
        
    }
    
    int recur(vector<int>& arr, int x, int k, vector<vector<int>> &memo) {
        
        if(k == 0) return 0;
        if(memo[x][k] != -1){
            return memo[x][k];
        }
        
        if(x+1 >= arr.size()) {
            return 0;
        }
        int ans = 0, mi = arr[x];
        
        for(int i = x+1; i< arr.size(); i++) {
            mi = min(mi, arr[i]);
            if(arr[i] > mi){
                ans =  max(ans, (arr[i] - mi) + recur(arr, i+1, k-1, memo));
            }
        }
        return memo[x][k] = ans;
        
    }
};