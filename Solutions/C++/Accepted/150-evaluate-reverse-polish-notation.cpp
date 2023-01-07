/*
Problem Title: 150 - Evaluate Reverse Polish Notation
Lang: C++
Runtime: 8 ms
Memory: 12 MB
Problem Url: https://leetcode.com/problems/evaluate-reverse-polish-notation
Submission Url: https://leetcode.com/problems/evaluate-reverse-polish-notation/submissions/498353835
*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int ans = 0;
        stack<int> st;
        for(string str : tokens){
            if(str == "/") {
                int f = st.top();st.pop();
                int s = st.top();st.pop();
                int res = s / f;
                st.push(res);
            }
            else if(str == "*") {
                int f = st.top();st.pop();
                int s = st.top();st.pop();
                int res = s * f;
                st.push(res);
            }
            else if(str == "-") {
                int f = st.top();st.pop();
                int s = st.top();st.pop();
                int res = s - f;
                st.push(res);
            }
            else if(str == "+") {
                int f = st.top();st.pop();
                int s = st.top();st.pop();
                int res = s + f;
                st.push(res);
            }
            else{
                int val = to_int(str);
                st.push(val);
            }
        }
        return st.top();
    }
    
    int to_int(string s){
        int ans = 0;
        int neg = 1;
        for(char ch : s){
            if(ch == '-'){
                neg = -1;
                continue;
            }
            ans = ans * 10 + int(ch-'0');
        }
        return ans * neg;
    }
};