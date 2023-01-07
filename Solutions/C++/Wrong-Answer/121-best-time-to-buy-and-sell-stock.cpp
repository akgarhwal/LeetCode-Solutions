/*
Problem Title: 121 - Best Time to Buy and Sell Stock
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/best-time-to-buy-and-sell-stock
Submission Url: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/595728494
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for(int i = 1 ; i < prices.size(); i++){
            if(prices[i] > prices[i-1]){
                ans += prices[i] - prices[i-1];
            }
        }
        return ans;
    }
};