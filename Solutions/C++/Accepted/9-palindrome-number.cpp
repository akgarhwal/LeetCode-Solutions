/*
Problem Title: 9 - Palindrome Number
Lang: C++
Runtime: 12 ms
Memory: 5.7 MB
Problem Url: https://leetcode.com/problems/palindrome-number
Submission Url: https://leetcode.com/problems/palindrome-number/submissions/867863767
*/

class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers will not be palindromes
        if (x < 0) {
            return false;
        }

        // Check to validate that the reverse of the number will be in the range of INT_MAX
        // If not, it will not be a palindrome
        if (x > INT_MAX / 10 && (x % 10 > 2)) {
            return false;
        }

        return reverse(x) == x;
    }

    int reverse(int x) {
        int y = 0;
        while (x) {
            // Multiply y by 10 to make room for the next digit, then add the last digit of x to y 
            y = y * 10 + x % 10; 
            // Divide x by 10 to remove the last digit 
            x /= 10; 
        }

        return y; 
    }
};