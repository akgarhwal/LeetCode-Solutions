/*
Problem Title: 402 - Remove K Digits
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/remove-k-digits
Submission Url: https://leetcode.com/problems/remove-k-digits/submissions/338917700
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
            if(st.empty() && i < num.size()){
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
            if((num[i] == '0' and ans == "")){
            }
            else{
                ans += num[i];
            }
            i++;
        }
        return ans==""?"0":ans;        
    }
};