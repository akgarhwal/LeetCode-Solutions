/*
Problem Title: 678 - Valid Parenthesis String
Lang: C++
Runtime: 0 ms
Memory: 6.2 MB
Problem Url: https://leetcode.com/problems/valid-parenthesis-string
Submission Url: https://leetcode.com/problems/valid-parenthesis-string/submissions/325745426
*/

class Solution {
public:
    
    bool checkValidString(string s) {
        int low = 0, high = 0;
        
        for(char ch : s){
            if(ch == '('){
                low++;high++;
            }
            else if(ch == ')'){
                low--;high--;
            }
            else{
                low--;
                high++;
            }
            if(high < 0) break;
            low = max(low, 0);
        }
        return low == 0;
    }
};