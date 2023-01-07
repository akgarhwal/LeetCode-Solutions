/*
Problem Title: 1359 - Count All Valid Pickup and Delivery Options
Lang: C++
Runtime: 0 ms
Memory: 7.6 MB
Problem Url: https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options
Submission Url: https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/submissions/308682286
*/

class Solution {
public:
    int countOrders(int n) {
        
        if(n <= 1){
            return n;
        }
        
        int ans = n;
        
        ans = (ans * 1LL * (2 * (n-1) + 1)) % 1000000007;
        
        ans = (ans * 1LL * countOrders(n - 1)) % 1000000007;
        
        return ans;
    }
};