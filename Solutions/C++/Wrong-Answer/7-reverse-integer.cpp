/*
Problem Title: 7 - Reverse Integer
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/reverse-integer
Submission Url: https://leetcode.com/problems/reverse-integer/submissions/308646236
*/

class Solution {
public:
    int reverse(int A) {
        int ans = 0;
        int isNeg = A < 0;

        while(A){

            if(ans > INT_MAX/10 || ans < INT_MIN/10 || (ans == INT_MAX/10 && A%10 > INT_MAX%10)){
                ans = 0;
                break;
            }

            ans = ans * 10 + A%10;
            A = A / 10;
        }

        ans = isNeg ? -ans : ans;

        return ans;
    }
};