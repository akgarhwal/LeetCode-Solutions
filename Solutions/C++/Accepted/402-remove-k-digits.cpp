/*
Problem Title: 402 - Remove K Digits
Lang: C++
Runtime: 8 ms
Memory: 6.9 MB
Problem Url: https://leetcode.com/problems/remove-k-digits
Submission Url: https://leetcode.com/problems/remove-k-digits/submissions/338920476
*/

class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size() <= k){
            return "0";
        }
        stack<char> st;
        st.push(num[0]);
        int i = 1;        
        while(k--){
            while(st.empty() && i < num.size()){
                if(num[i] != '0')
                    st.push(num[i]);
                i++;
            }
            while( i < num.size() and num[i] >= st.top() ){
                st.push(num[i]);
                i++;
            }
            st.pop();
        }
        string ans = "";
        int index = 0;
        while(!st.empty()){
            ans = st.top()+ans;
            st.pop();
        }
        while(i < num.size()){
            if( (num[i] != '0') or (num[i] == '0' and ans != "")){
                ans += num[i];
            }
            i++;
        }
        return ans==""?"0":ans;        
    }
};