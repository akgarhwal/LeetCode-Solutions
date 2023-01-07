/*
Problem Title: 1903 - Largest Odd Number in String
Lang: C++
Runtime: 32 ms
Memory: 15 MB
Problem Url: https://leetcode.com/problems/largest-odd-number-in-string
Submission Url: https://leetcode.com/problems/largest-odd-number-in-string/submissions/510391620
*/

class Solution {
public:
    string largestOddNumber(string num) {
        int pos = num.size()-1;
        while(pos>-1 and  (num[pos]-'0')%2 != 1){
            pos--;
        }
        return num.substr(0,pos+1);
    }
};