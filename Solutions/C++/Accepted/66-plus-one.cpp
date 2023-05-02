/*
Problem Title: 66 - Plus One
Lang: C++
Runtime: 0 ms
Memory: 8.7 MB
Problem Url: https://leetcode.com/problems/plus-one
Submission Url: https://leetcode.com/problems/plus-one/submissions/942464794
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());

        int carry = 1;

        for(int i = 0; i < digits.size(); i++) {
            int sum = digits[i] + carry;

            digits[i] = sum%10;
            carry = sum/10;
        }

        if(carry) {
            digits.push_back(carry);
        }
        
        reverse(digits.begin(), digits.end());

        return digits;
    }
};