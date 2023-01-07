/*
Problem Title: 714 - Best Time to Buy and Sell Stock with Transaction Fee
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee
Submission Url: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/submissions/484651956
*/

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        
        vector<int> memo(prices.size()+1, -1);
        return rec(prices, fee, 0, memo);
        
    }
    
    int rec(vector<int>& arr, int fee, int x, vector<int> &memo){
        
        
        
        if(x >= arr.size()){
            return 0;
        }
        
        if(memo[x] != -1){
            return memo[x];
        }
        
        int ans = 0, mi = arr[x];
        
        for(int i = x+1;i<arr.size();i++) {
            
            mi = min(mi, arr[i]);
            
            if(arr[i]-mi-fee > 0){
                
                ans = max(ans, arr[i]-mi-fee + rec(arr, fee, i+1, memo));
                
            }
            
        }
        
        return memo[x] = ans;
        
    }
};