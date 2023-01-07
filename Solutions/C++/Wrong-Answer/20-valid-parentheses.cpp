/*
Problem Title: 20 - Valid Parentheses
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/valid-parentheses
Submission Url: https://leetcode.com/problems/valid-parentheses/submissions/332409389
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char ch : s){
            if(ch == '(' or ch == '{' or ch == '['){
                st.push(ch);
            }
            else if(st.empty()){
                return false;
            }
            else if ( (ch == ')' and st.top() == '(') or 
                (ch == '}' and st.top() == '{')
                or (ch == ']' and st.top() == '[') ) {
                    st.pop();
                }
        }
        return st.empty();
    }
};