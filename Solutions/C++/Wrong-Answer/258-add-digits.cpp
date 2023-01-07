/*
Problem Title: 258 - Add Digits
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/add-digits
Submission Url: https://leetcode.com/problems/add-digits/submissions/371773576
*/

class Solution {
public:
    int addDigits(int num) {
        return num <=9 ? num : num%9;
    }
};