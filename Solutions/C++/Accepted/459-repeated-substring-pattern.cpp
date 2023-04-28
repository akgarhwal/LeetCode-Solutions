/*
Problem Title: 459 - Repeated Substring Pattern
Lang: C++
Runtime: 43 ms
Memory: 40 MB
Problem Url: https://leetcode.com/problems/repeated-substring-pattern
Submission Url: https://leetcode.com/problems/repeated-substring-pattern/submissions/940743855
*/

class Solution {
public:
    bool helper(string s, int len) {
        int index = 0;

        for(int i=0; i < s.size(); i++) {
            if(s[i] != s[index%len]) {
                return false;
            }
            index += 1;
        }

        return true;
    }
    bool repeatedSubstringPattern(string s) {
        int len = 1;

        while(len < s.size() and len <= 10000) {
            if( (s.size()%len) == 0 and helper(s, len)) {
                return true;
            }
            len += 1;
        }

        return false;
    }
};