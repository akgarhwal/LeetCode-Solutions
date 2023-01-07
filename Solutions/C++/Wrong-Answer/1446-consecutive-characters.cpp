/*
Problem Title: 1446 - Consecutive Characters
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/consecutive-characters
Submission Url: https://leetcode.com/problems/consecutive-characters/submissions/340174260
*/

class Solution {
public:
    int maxPower(string s) {
        int po = 0, ans = 1;
        char c = s[0];
        for(char ch: s){
            if(ch == c){
                po++;
            }
            else{
                c = ch;
                ans = max(ans, po);
                po = 1;
            }
        }
        return ans;
    }
};