/*
Problem Title: 2309 - Greatest English Letter in Upper and Lower Case
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/greatest-english-letter-in-upper-and-lower-case
Submission Url: https://leetcode.com/problems/greatest-english-letter-in-upper-and-lower-case/submissions/727316528
*/

class Solution {
public:
    string greatestLetter(string s) {
        string res = "";
        bool lowerCaseMap[26] = {false};
        
        for(char ch : s){
            if(ch >= 'a' and ch <= 'z'){
                lowerCaseMap[ch-'a'] = true;
            }
            else{
                if(lowerCaseMap[(ch-'A')] and (res.size() == 0 or (res.size() > 1 and res[0] < ch ))){
                    res = ch;
                }
            }
        }
        return res;
    }
};