/*
Problem Title: 43 - Multiply Strings
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/multiply-strings
Submission Url: https://leetcode.com/problems/multiply-strings/submissions/942596525
*/

class Solution {
public:

    string multiplyByDigit(string num , int digit) {
        string ans = "";
        int c = 0;

        for(int i = num.size()-1; i >= 0 ; i--) {

            int res = (num[i] - '0') * digit + c;
            ans += char((res%10) + '0');
            c = res / 10;
        }
        while (c) {
            ans += (c%10 + '0');
            c = c/10;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }

    string add(string n1, string n2) {

        reverse(n1.begin(), n1.end());
        reverse(n2.begin(), n2.end());

        int i = 0, c = 0;
        string res = "";

        while( i < n1.size() or i < n2.size()) {
            int d1 = i >= n1.size() ? 0 : n1[i] - '0';
            int d2 = i >= n2.size() ? 0 : n2[i] - '0';

            int sum = d1 + d2 + c;

            res += char(sum%10 + '0');
            c = sum/10;

            i++;
        }

        // while (c) {
        //     res += (c%10 + '0');
        //     c = c/10;
        // }

        reverse(res.begin(), res.end());
        return res;
    }

    string multiply(string num1, string num2) {
        
        string ans = "", shift = "";

        for(int i = num2.size()-1; i >= 0; i--) {

            string res = multiplyByDigit(num1, num2[i] - '0');
            ans = add(ans, res + shift);
            shift += "0";
        }

        int x = 0;
        while( x < (ans.size()-1) ) {
            if(ans[x] == '0') {
                x++;
            } else {
                break;
            }
        }

        return ans.substr(x);
    }
};