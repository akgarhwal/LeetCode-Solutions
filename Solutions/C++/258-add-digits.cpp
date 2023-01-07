/*
Problem Title: 258 - Add Digits
Lang: C++
Runtime: 0 ms
Memory: 5.9 MB
Problem Url: https://leetcode.com/problems/add-digits
Submission Url: https://leetcode.com/problems/add-digits/submissions/371774151
*/

class Solution {
public:
    int addDigits(int num) {
        return num%9 == 0 ? (num == 0 ? 0 : 9) : num%9 ;
    }
};