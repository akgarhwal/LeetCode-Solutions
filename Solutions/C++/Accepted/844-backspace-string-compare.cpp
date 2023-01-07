/*
Problem Title: 844 - Backspace String Compare
Lang: C++
Runtime: 0 ms
Memory: 6.4 MB
Problem Url: https://leetcode.com/problems/backspace-string-compare
Submission Url: https://leetcode.com/problems/backspace-string-compare/submissions/774374387
*/

class Solution {
public:
    string prcessString(string str){
        string res = "";
        int i = 0;
        while(i < str.size()){
            if(str[i] != '#'){
                res += str[i];
            }
            else if(res.size() > 0){
                 res.pop_back();                
            }
            i += 1;
        }
        return res;
    }
    bool backspaceCompare(string S, string T) {
        return prcessString(S) == prcessString(T);
    }
};