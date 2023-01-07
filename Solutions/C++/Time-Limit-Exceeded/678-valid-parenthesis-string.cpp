/*
Problem Title: 678 - Valid Parenthesis String
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/valid-parenthesis-string
Submission Url: https://leetcode.com/problems/valid-parenthesis-string/submissions/325590625
*/

class Solution {
public:
    
    bool checkString(string s, int pos, int open, int close){
        if(pos == s.size()){
            return open == close;
        }
        bool ans = false;
        for(int i = pos; i < s.size(); i++){
            if(close > open){
                return false;
            }
            if(s[i] == '*'){
                ans = ans or checkString(s, i+1, open, close);
                ans = ans or checkString(s, i+1, open+1, close);
                ans = ans or checkString(s, i+1, open, close+1);
                return ans;
            }
            else if(s[i] == '('){
                open++;
            }
            else{
                close++;
            }
        }
        ans = ans or (open == close);
        return ans;
    }
    
    bool checkValidString(string s) {
        return checkString(s, 0, 0, 0);
    }
};