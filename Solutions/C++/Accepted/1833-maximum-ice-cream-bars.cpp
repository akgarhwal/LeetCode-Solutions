/*
Problem Title: 1833 - Maximum Ice Cream Bars
Lang: C++
Runtime: 477 ms
Memory: 76.6 MB
Problem Url: https://leetcode.com/problems/maximum-ice-cream-bars
Submission Url: https://leetcode.com/problems/maximum-ice-cream-bars/submissions/872280189
*/

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int ans = 0;
        for(int cost : costs){
            if(cost <= coins){
                ans += 1;
                coins -= cost;
            }
        }
        return ans;
    }
};