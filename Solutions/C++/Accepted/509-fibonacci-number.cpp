/*
Problem Title: 509 - Fibonacci Number
Lang: C++
Runtime: 18 ms
Memory: 6 MB
Problem Url: https://leetcode.com/problems/fibonacci-number
Submission Url: https://leetcode.com/problems/fibonacci-number/submissions/772312694
*/

class Solution {
public:
    int fib(int n) {
        if(n == 0 or n == 1){
            return n;
        }
        return fib(n-1) + fib(n-2);
    }
};