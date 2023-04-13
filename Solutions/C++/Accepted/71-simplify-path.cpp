/*
Problem Title: 71 - Simplify Path
Lang: C++
Runtime: 10 ms
Memory: 10.8 MB
Problem Url: https://leetcode.com/problems/simplify-path
Submission Url: https://leetcode.com/problems/simplify-path/submissions/932584260
*/

class Solution {
public:
    string simplifyPath(string path) {
        
        stack<string> st;
        string res = "";
        
        for(int i = 0; i < path.size(); ++i) {
            if(path[i] == '/') {
                continue;
            }

            string temp = "";
            while(i < path.size() && path[i] != '/') {
                temp += path[i];
                ++i;
            }

            if(temp == ".") {
                continue;
            }

            if(temp == "..") {
                if(!st.empty()) {
                    st.pop();
                }
            } else {
                st.push(temp);
            }
        }
        
        while(!st.empty()) {
            res = "/" + st.top() + res;
            st.pop();
        }
        
        if(res.size() == 0) {
            res = "/";
        }
        
        return res;
    }
};