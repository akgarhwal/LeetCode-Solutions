/*
Problem Title: 2413 - Smallest Even Multiple
Lang: C++
Runtime: 0 ms
Memory: 6 MB
Problem Url: https://leetcode.com/problems/smallest-even-multiple
Submission Url: https://leetcode.com/problems/smallest-even-multiple/submissions/868363812
*/

class Solution {
public:
    int smallestEvenMultiple(int n) {
        return (n&1) > 0 ? n<<1 : n;
    }
};