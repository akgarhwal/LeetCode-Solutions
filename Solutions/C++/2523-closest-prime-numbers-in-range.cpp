/*
Problem Title: 2523 - Closest Prime Numbers in Range
Lang: C++
Runtime: 2224 ms
Memory: 15.4 MB
Problem Url: https://leetcode.com/problems/closest-prime-numbers-in-range
Submission Url: https://leetcode.com/problems/closest-prime-numbers-in-range/submissions/868821337
*/

class Solution {
public:
    
    vector<int> findPrimes(int x, int y) {
        vector<int> ans;
        x = max(2, x);
        for (int i = x; i <= y; i++) {
            bool isPrime = true;
            for (int j = 2; j * j <= i; j++) {
                if (i % j == 0) {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime) {
               ans.push_back(i);
            }
        }
        return ans;
    }
    
    vector<int> closestPrimes(int left, int right) {
        vector<int> primes = findPrimes(left, right);
        
        vector<int> ans(2, -1);
        int minDiff = INT_MAX;
        
        for(int i = 0; i < ((int)primes.size())-1; i++ ) {
            if(minDiff > (primes[i+1] - primes[i])) {
                ans[0] = primes[i];
                ans[1] = primes[i+1];
                minDiff = primes[i+1] - primes[i];
            }
        }
        return ans;
    }
};