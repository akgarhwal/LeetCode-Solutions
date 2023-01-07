/*
Problem Title: 1672 - Richest Customer Wealth
Lang: C++
Runtime: 6 ms
Memory: 7.8 MB
Problem Url: https://leetcode.com/problems/richest-customer-wealth
Submission Url: https://leetcode.com/problems/richest-customer-wealth/submissions/873490635
*/

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0;
        for(int i=0;i<accounts.size();i++) {
            int sum = 0;
            for(int j = 0; j < accounts[0].size(); j++) {
                sum += accounts[i][j];
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};