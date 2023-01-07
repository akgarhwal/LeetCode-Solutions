/*
Problem Title: 191 - Number of 1 Bits
Lang: C++
Runtime: 4 ms
Memory: 8.2 MB
Problem Url: https://leetcode.com/problems/number-of-1-bits
Submission Url: https://leetcode.com/problems/number-of-1-bits/submissions/305491477
*/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while (n){
            ans += (n&1);
            n = n>>1;
        }
        return ans;
    }
};