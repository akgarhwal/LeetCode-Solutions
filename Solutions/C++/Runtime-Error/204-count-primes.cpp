/*
Problem Title: 204 - Count Primes
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/count-primes
Submission Url: https://leetcode.com/problems/count-primes/submissions/491201019
*/

class Solution {
public:
    int countPrimes(int n) {
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