/*
Problem Title: 394 - Decode String
Lang: C++
Runtime: 3 ms
Memory: 11.7 MB
Problem Url: https://leetcode.com/problems/decode-string
Submission Url: https://leetcode.com/problems/decode-string/submissions/774983454
*/

class Solution {
public:
    
    bool is_digit(char ch){
        return ch >= '0' and ch <= '9';
    }
    
    int to_digit(char ch){
        return ch - '0';
    }
    
    string decodeString(string s) {
        stack<char> st;
        
        for( int i = 0; i < s.size(); i++) {
            if(s[i] != ']') {
                st.push(s[i]);
            }
            else{
                string str = "";
                while(st.top() != '[') {
                    str = st.top() + str; 
                    st.pop();
                }
                
                st.pop(); // pop '['
                int mul = 0;
                string numStr = "";
                while(!st.empty() and is_digit(st.top()) ) {
                    //mul = to_digit(st.top()) * 10 + mul;
                    numStr = st.top() + numStr;
                    st.pop();
                }
                
                for(int j = 0; j < numStr.size(); j++) {
                    mul = mul * 10 + to_digit(numStr[j]);
                }
                
                string temp = "";
                while(mul--){
                    temp = temp + str;
                }
                int ind = 0;
                while( ind < temp.size()){
                    st.push(temp[ind++]);
                }
            }
        }
        
        string res = "";
        while( !st.empty() ) {
            res = st.top() + res;
            st.pop();
        }
        
        return res;
    }
};