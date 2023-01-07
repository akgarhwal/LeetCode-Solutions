/*
Problem Title: 231 - Power of Two
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/power-of-two
Submission Url: https://leetcode.com/problems/power-of-two/submissions/309309621
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return !(n&(n-1));
    }
};