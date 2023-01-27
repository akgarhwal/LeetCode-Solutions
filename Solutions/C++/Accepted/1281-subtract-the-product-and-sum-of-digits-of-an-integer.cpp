/*
Problem Title: 1281 - Subtract the Product and Sum of Digits of an Integer
Lang: C++
Runtime: 0 ms
Memory: 6 MB
Problem Url: https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer
Submission Url: https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/submissions/885350193
*/

class Solution {
public:
    int subtractProductAndSum(int n) {
        int product = 1, sum = 0;
        while(n) {
            int digit = n%10;
            product *= digit;
            sum += digit;
            n = n/10;
        }
        return product-sum;
    }
};