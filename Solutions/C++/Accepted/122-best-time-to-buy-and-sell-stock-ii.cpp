/*
Problem Title: 122 - Best Time to Buy and Sell Stock II
Lang: C++
Runtime: 4 ms
Memory: 13 MB
Problem Url: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii
Submission Url: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/submissions/484552518
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for(int i=1;i<prices.size();i++){
            ans += max(0, prices[i]-prices[i-1]);
        }
        return ans;
    }
};