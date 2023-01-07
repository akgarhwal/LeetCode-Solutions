/*
Problem Title: 1704 - Determine if String Halves Are Alike
Lang: C++
Runtime: 0 ms
Memory: 6.8 MB
Problem Url: https://leetcode.com/problems/determine-if-string-halves-are-alike
Submission Url: https://leetcode.com/problems/determine-if-string-halves-are-alike/submissions/434972742
*/

class Solution {
public:
    bool halvesAreAlike(string s) {
        int len = s.size()/2;
        int c1 = 0, c2 =0;
        
        for(int i=0;i<s.size();i++){
                if( s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u' or s[i] == 'A' or s[i] == 'E' or s[i] == 'I' or s[i] == 'O' or s[i] == 'U') {
                    if(i < len)
                    c1++;
                    else
                    c2++;
                }
                
        }
        
        return c1 == c2;
    }
};