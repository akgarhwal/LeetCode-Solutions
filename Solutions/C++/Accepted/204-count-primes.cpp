/*
Problem Title: 204 - Count Primes
Lang: C++
Runtime: 44 ms
Memory: 7.1 MB
Problem Url: https://leetcode.com/problems/count-primes
Submission Url: https://leetcode.com/problems/count-primes/submissions/491201203
*/

class Solution {
public:
    int countPrimes(int n) {
        if(n == 0) return 0;
        vector<bool> isPrime(n, true);
       isPrime[0] = isPrime[1] = false;
       for (int i = 2; i * i < n; i++) {
          if (!isPrime[i]) continue;
          for (int j = i * i; j < n; j += i) {
             isPrime[j] = false;
          }
       }
       int count = 0;
       for (int i = 2; i < n; i++) {
          if (isPrime[i]) count++;
       }
       return count;
    }
};