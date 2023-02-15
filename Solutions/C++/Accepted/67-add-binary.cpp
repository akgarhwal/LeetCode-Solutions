/*
Problem Title: 67 - Add Binary
Lang: C++
Runtime: 0 ms
Memory: 6.3 MB
Problem Url: https://leetcode.com/problems/add-binary
Submission Url: https://leetcode.com/problems/add-binary/submissions/897533445
*/

class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());


        int i = 0, j = 0, c = 0, x = 0, y = 0;

        while( i < a.size() and j < b.size()) {
            
            x = a[i] - '0';
            y = b[j] - '0';

            if(x + y + c == 2) {
                ans += '0';
                c = 1;
            } else if(x + y + c == 3) {
                ans += '1';
                c = 1;
            } else {
                ans += char(x + y + c + 48);
                c = 0;
            }
            i++;
            j++;
        }

        while( i < a.size()) {
            x = a[i] - '0';
            if(x + c == 2) {
                ans += '0';
                c = 1;
            } else {
                ans += char(x + c + 48);
                c = 0;
            }
            i++;
        }
        while( j < b.size()) {
            x = b[j] - '0';
            if(x + c == 2) {
                ans += '0';
                c = 1;
            } else {
                ans += char(x + c + 48);
                c = 0;
            }
            j++;
        }

        if(c == 1) {
            ans += '1';
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};