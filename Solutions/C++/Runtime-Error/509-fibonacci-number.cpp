/*
Problem Title: 509 - Fibonacci Number
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/fibonacci-number
Submission Url: https://leetcode.com/problems/fibonacci-number/submissions/592473123
*/

class Solution {
public:
    int fib(int n) {
        vector<int> fibo(n+2, 0);
        fibo[0] = 0;
        fibo[1] = 1;
        
        for(int index = 2; index <= n; index++){
            fibo[index] = fibo[index-1] + fibo[index-2] + fibo[index-3];
        }
        return fibo[n];
    }
};