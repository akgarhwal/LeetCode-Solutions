/*
Problem Title: 326 - Power of Three
Lang: C++
Runtime: 31 ms
Memory: 6.2 MB
Problem Url: https://leetcode.com/problems/power-of-three
Submission Url: https://leetcode.com/problems/power-of-three/submissions/781748384
*/

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n == 0) return false;
        double x = log10(n) / log10(3);
        return x == floor(x);
    }
};