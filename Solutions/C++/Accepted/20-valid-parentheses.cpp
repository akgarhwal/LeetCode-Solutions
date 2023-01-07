/*
Problem Title: 20 - Valid Parentheses
Lang: C++
Runtime: 0 ms
Memory: 6.2 MB
Problem Url: https://leetcode.com/problems/valid-parentheses
Submission Url: https://leetcode.com/problems/valid-parentheses/submissions/332410047
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char ch : s){
            if(ch == '(' or ch == '{' or ch == '['){
                st.push(ch);
            }
            else if ( !st.empty() and ((ch == ')' and st.top() == '(') or 
                (ch == '}' and st.top() == '{')
                or (ch == ']' and st.top() == '[')) ) {
                    st.pop();
                }
            else {
                return false;
            }
        }
        return st.empty();
    }
};