/*
Problem Title: 2390 - Removing Stars From a String
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/removing-stars-from-a-string
Submission Url: https://leetcode.com/problems/removing-stars-from-a-string/submissions/931603241
*/

class Solution {
public:
    string removeStars(string s) {
        stack<char> st;

        for(char ch : s) {
            if(ch == '*') {
                st.pop();
            } else {
                st.push(ch);
            }
        }

        string ans = "";
        
        while(!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};