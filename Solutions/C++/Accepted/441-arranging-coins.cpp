/*
Problem Title: 441 - Arranging Coins
Lang: C++
Runtime: 8 ms
Memory: 6.2 MB
Problem Url: https://leetcode.com/problems/arranging-coins
Submission Url: https://leetcode.com/problems/arranging-coins/submissions/360594964
*/

class Solution {
public:
    int arrangeCoins(int n) {
        int t = 0, i = 1;
        while( n-i >= 0){
            n -= i;
            i++;
        }
        return i-1;
    }
};