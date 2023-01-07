/*
Problem Title: 1047 - Remove All Adjacent Duplicates In String
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string
Submission Url: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/submissions/514776618
*/

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        int i = 0, N = s.size();
        while(i < N){
            while(i < N and !st.empty() and s[i] == st.top()){
                st.pop();
                i++;
            }
            if( i < N)
                st.push(s[i]);   
            i++;
        }
        string ans = "";
        while(!st.empty()){
            ans = ans +  st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};