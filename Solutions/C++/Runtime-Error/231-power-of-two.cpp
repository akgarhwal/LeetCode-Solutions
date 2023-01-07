/*
Problem Title: 231 - Power of Two
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/power-of-two
Submission Url: https://leetcode.com/problems/power-of-two/submissions/309310353
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n==0 ? false : !(n&(n-1));
    }
};