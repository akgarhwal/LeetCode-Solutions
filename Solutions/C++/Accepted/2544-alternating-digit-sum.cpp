/*
Problem Title: 2544 - Alternating Digit Sum
Lang: C++
Runtime: 3 ms
Memory: 5.9 MB
Problem Url: https://leetcode.com/problems/alternating-digit-sum
Submission Url: https://leetcode.com/problems/alternating-digit-sum/submissions/882764776
*/

class Solution {
public:
    int alternateDigitSum(int n) {
        string s = to_string(n);
        int sum = 0;
        bool sign = true;
        for(char ch : s){
            if(sign){
                sum += (ch-'0');
            }
            else{
                sum -= (ch-'0');
            }
            sign = !sign;
        }
        return sum;
    }
};