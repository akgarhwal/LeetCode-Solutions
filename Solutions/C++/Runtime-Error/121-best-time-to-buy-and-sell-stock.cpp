/*
Problem Title: 121 - Best Time to Buy and Sell Stock
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/best-time-to-buy-and-sell-stock
Submission Url: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/320492604
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int max_profit = 0;
        int min_so_far = prices[0];
        
        for(int price : prices){
            
            min_so_far = min(min_so_far, price); 
            max_profit = max(max_profit, (price - min_so_far));
            
        }
        
        return max_profit;
    }
};