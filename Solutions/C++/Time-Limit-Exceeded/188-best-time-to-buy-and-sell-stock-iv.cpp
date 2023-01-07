/*
Problem Title: 188 - Best Time to Buy and Sell Stock IV
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv
Submission Url: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/submissions/484618441
*/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        
        return recur(prices, 0, k);
        
    }
    
    int recur(vector<int>& arr, int x, int k) {
        
        if(k == 0) return 0;
        if(x+1 >= arr.size()) {
            return 0;
        }
        
        int ans = 0, mi = arr[x];
        
        for(int i = x+1; i< arr.size(); i++) {
            
            mi = min(mi, arr[i]);
            
            if(arr[i] > mi){
                
                ans =  max(ans, (arr[i] - mi) + recur(arr, i+1, k-1));
                
            }
            // else{
            //     ans += recur
            // }
            
        }
        return ans;
        
    }
};