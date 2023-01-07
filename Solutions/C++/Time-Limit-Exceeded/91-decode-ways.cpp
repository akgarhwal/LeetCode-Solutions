/*
Problem Title: 91 - Decode Ways
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/decode-ways
Submission Url: https://leetcode.com/problems/decode-ways/submissions/434734086
*/

class Solution {
public:
    int numDecodings(string s) {
        if(s.size() == 0) return 1;
        if(s.size() == 1){
            return s[0] == '0' ? 0 : 1;
        }
        int x = s[0] - '0',ans = 0, y = s[1] - '0';
        if(x > 0){
            ans = numDecodings(s.substr(1,string::npos));
        }
        if( x > 0 and (x*10+y) < 27){
            ans += numDecodings(s.substr(2,string::npos));
        }
        return ans;
    }
};