/*
Problem Title: 231 - Power of Two
Lang: C++
Runtime: 0 ms
Memory: 6.2 MB
Problem Url: https://leetcode.com/problems/power-of-two
Submission Url: https://leetcode.com/problems/power-of-two/submissions/350671845
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n<=0 ? false : !(n&(n-1));
    }
};