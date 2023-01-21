/*
Problem Title: 2396 - Strictly Palindromic Number
Lang: C++
Runtime: 0 ms
Memory: 5.9 MB
Problem Url: https://leetcode.com/problems/strictly-palindromic-number
Submission Url: https://leetcode.com/problems/strictly-palindromic-number/submissions/881620173
*/

class Solution {
public:

    string convertToBase(int num, int base) {
        string ans = "";
        while(num > 0){
            ans += to_string(num%base);
            num = num / base;
        }
        return ans;
    }

    bool isStrictlyPalindromic(int n) {
        string numStr = "";
        for(int i=2; i <= n-2; i++){
            numStr = convertToBase(n, i);
            string reverseNumStr = numStr;
            reverse(reverseNumStr.begin(), reverseNumStr.end());
            if(reverseNumStr != numStr){
                return false;
            }
        }
        return true;
    }
};