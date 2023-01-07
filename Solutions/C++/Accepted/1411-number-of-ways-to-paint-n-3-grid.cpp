/*
Problem Title: 1411 - Number of Ways to Paint N × 3 Grid
Lang: C++
Runtime: 4 ms
Memory: 6 MB
Problem Url: https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid
Submission Url: https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/submissions/323569786
*/

class Solution {
public:
    int numOfWays(int n) {
        int MOD = 1e9 + 7;
        int res3 = 6, res2 = 6;
        int step = 2;
        while(step <= n){
            int temp = (2LL * (res3) + 2LL * (res2))%MOD;
            res2 = (2LL * res3 + 3LL * res2)%MOD;
            res3 = temp;
            step++;
        }
        
        return (res3 + res2)%MOD;
        
    }
};