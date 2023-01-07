/*
Problem Title: 1446 - Consecutive Characters
Lang: C++
Runtime: 12 ms
Memory: 6.7 MB
Problem Url: https://leetcode.com/problems/consecutive-characters
Submission Url: https://leetcode.com/problems/consecutive-characters/submissions/340174440
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
        ans = max(ans, po);
        return ans;
    }
};