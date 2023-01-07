/*
Problem Title: 121 - Best Time to Buy and Sell Stock
Lang: C++
Runtime: 201 ms
Memory: 93.4 MB
Problem Url: https://leetcode.com/problems/best-time-to-buy-and-sell-stock
Submission Url: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/766304347
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, minSoFar = prices[0];
        for(int i=1; i < prices.size(); i++) {
            ans = max(ans, prices[i]-minSoFar);
            minSoFar = min(minSoFar, prices[i]);            
        }
        return ans;
    }
};