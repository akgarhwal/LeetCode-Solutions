/*
Problem Title: 201 - Bitwise AND of Numbers Range
Lang: C++
Runtime: 8 ms
Memory: 6.1 MB
Problem Url: https://leetcode.com/problems/bitwise-and-of-numbers-range
Submission Url: https://leetcode.com/problems/bitwise-and-of-numbers-range/submissions/329124390
*/

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int ans = 0;
        while( m != n){
            m = m >> 1;
            n = n >> 1;
            ans++;
        }
        return m * (1 << ans);
    }
};