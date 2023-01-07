/*
Problem Title: 309 - Best Time to Buy and Sell Stock with Cooldown
Lang: C++
Runtime: 252 ms
Memory: 11.3 MB
Problem Url: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown
Submission Url: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/submissions/484632691
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        vector<int> memo(prices.size()+1,-1);
        return recur(prices, 0, memo);
        
    }
    
    int recur(vector<int>& arr, int x, vector<int> &memo) {
        
        
        
        if(x >= arr.size()) {
            return 0;
        }
        if(memo[x] != -1){
            return memo[x];
        }
        int ans = 0, mi = arr[x];
        
        for(int i = x+1; i< arr.size(); i++) {
            mi = min(mi, arr[i]);
            if(arr[i] > mi){
                ans =  max(ans, (arr[i] - mi) + recur(arr, i+2, memo));
            }
        }
        return memo[x] = ans;
        
    }
};