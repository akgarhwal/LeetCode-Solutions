/*
Problem Title: 2520 - Count the Digits That Divide a Number
Lang: C++
Runtime: 3 ms
Memory: 6 MB
Problem Url: https://leetcode.com/problems/count-the-digits-that-divide-a-number
Submission Url: https://leetcode.com/problems/count-the-digits-that-divide-a-number/submissions/870953171
*/

class Solution {
public:
    int countDigits(int num) {
        int num2 = num, ans = 0;
        while (num > 0) {
            int d = num % 10;
            if((num2 % d) == 0) {
                ans += 1;
            }
            num = num / 10;
        }
        return ans;
    }
};