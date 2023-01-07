/*
Problem Title: 32 - Longest Valid Parentheses
Lang: C++
Runtime: 4 ms
Memory: 7.3 MB
Problem Url: https://leetcode.com/problems/longest-valid-parentheses
Submission Url: https://leetcode.com/problems/longest-valid-parentheses/submissions/501277695
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        stack<int> st;
        for(int i=0;i<s.size();i++){
            
            if(s[i] == '('){
                st.push(i);
            }
            else{
                
                if(st.empty()){
                    st.push(i);
                }
                else if(s[st.top()] == '('){
                    st.pop();
                    if(st.empty()){
                        ans = max(ans, i+1);
                    }
                    else{
                        ans = max(ans, i - st.top());
                    }
                }
                else{
                    st.push(i);
                }
                
            }
            
        }
        return ans;
    }
};

