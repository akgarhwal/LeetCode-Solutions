/*
Problem Title: 402 - Remove K Digits
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/remove-k-digits
Submission Url: https://leetcode.com/problems/remove-k-digits/submissions/338912327
*/

class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size() <= k){
            return "0";
        }
        while(k--){
            int i = 1;        
            while( i < num.size() and num[i] >= num[i-1] ){
                i++;
            }
            num.erase(i-1,1);
        }
        string ans = "";
        int index = 0;
        while(index < num.size()){
            if( num[index] == '*' or (num[index] == '0' and ans == "")){
            }
            else{
                ans += num[index];
            }
            index++;
        }
        return ans == "" ? "0" : ans;
};