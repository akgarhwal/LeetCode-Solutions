/*
Problem Title: 1047 - Remove All Adjacent Duplicates In String
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string
Submission Url: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/submissions/514772315
*/

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        int i = 0, N = s.size();
        while(i < N){
            while(i < N and !st.empty() and s[i] == st.top()){
                while(i< N and st.top() == s[i]){
                    i++;
                }
                st.pop();
            }
            if( i < N)
                st.push(s[i]);   
            i++;
        }
        string ans = "";
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};