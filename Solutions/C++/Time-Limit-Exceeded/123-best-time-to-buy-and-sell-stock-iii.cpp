/*
Problem Title: 123 - Best Time to Buy and Sell Stock III
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii
Submission Url: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/submissions/484631133
*/

class Solution {
public:
    int count = 0;
    int maxProfit(vector<int>& prices) {
        
        vector<vector<int>> memo(prices.size()+1, vector<int>(2+1, -1));
    
        int ans =  recur(prices, 0, 2, memo);
        //cout<<"C : " <<count<<endl;
        return ans;
    }
    
    int recur(vector<int>& arr, int x, int k, vector<vector<int>> &memo) {
        
        if(k == 0) return 0;
        if(memo[x][k] != -1){
            return memo[x][k];
        }
        count+=1;
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