/*
Problem Title: 2521 - Distinct Prime Factors of Product of Array
Lang: C++
Runtime: 107 ms
Memory: 36.6 MB
Problem Url: https://leetcode.com/problems/distinct-prime-factors-of-product-of-array
Submission Url: https://leetcode.com/problems/distinct-prime-factors-of-product-of-array/submissions/868811730
*/

class Solution {
public:
    
    set<int> primeFactors(int n) {
        set<int> ans;
        
        while (n % 2 == 0) {
            ans.insert(2);
            n = n/2;
        }
        for (int i = 3; i <= sqrt(n); i = i + 2) {
            while (n % i == 0) {
                ans.insert(i);
                n = n/i;
            }
        }
        if (n > 2) {
            ans.insert(n);
        }
        return ans;
    }
    
    int distinctPrimeFactors(vector<int>& nums) {
        set<int> ans;
        for(int num : nums) {
            auto st = primeFactors(num);
            ans.insert(st.begin(), st.end());
        }
        return ans.size();
    }
};