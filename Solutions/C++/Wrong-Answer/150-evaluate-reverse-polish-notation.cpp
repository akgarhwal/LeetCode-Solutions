/*
Problem Title: 150 - Evaluate Reverse Polish Notation
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/evaluate-reverse-polish-notation
Submission Url: https://leetcode.com/problems/evaluate-reverse-polish-notation/submissions/498353399
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
        for(char ch : s){
            ans = ans * 10 + int(ch-'0');
        }
        return ans;
    }
};