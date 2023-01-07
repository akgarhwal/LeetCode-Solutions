/*
Problem Title: 709 - To Lower Case
Lang: C++
Runtime: 0 ms
Memory: 6 MB
Problem Url: https://leetcode.com/problems/to-lower-case
Submission Url: https://leetcode.com/problems/to-lower-case/submissions/497647824
*/

class Solution {
public:
    string toLowerCase(string s) {
        string ans = "";
        for(char ch : s){
            if(ch >= 'A' and ch <= 'Z'){
                ans += char(ch - 'A' + 'a');
            }
            else{
                ans += ch;
            }
        }
        return ans;
    }
};