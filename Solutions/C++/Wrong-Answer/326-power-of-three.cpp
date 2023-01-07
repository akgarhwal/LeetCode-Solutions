/*
Problem Title: 326 - Power of Three
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/power-of-three
Submission Url: https://leetcode.com/problems/power-of-three/submissions/485891481
*/

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n == 0) return false;
        double x = log((double)n) / log(3.0);
        // cout << std::setprecision(20) << x << '\n';
        return x-floor(x) < 0.0000000000000001;
    }
};