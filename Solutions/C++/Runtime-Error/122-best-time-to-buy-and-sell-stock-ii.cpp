/*
Problem Title: 122 - Best Time to Buy and Sell Stock II
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii
Submission Url: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/submissions/320495624
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int max_profit = 0;
        
        for(int day = 0; day < prices.size()-1; day++) {
            
            if(prices[day+1] > prices[day]){
                max_profit += (prices[day+1] - prices[day]);
            }
            
        }
        
        return max_profit;
    }
};