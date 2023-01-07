/*
Problem Title: 1370 - Increasing Decreasing String
Lang: C++
Runtime: 20 ms
Memory: 9.7 MB
Problem Url: https://leetcode.com/problems/increasing-decreasing-string
Submission Url: https://leetcode.com/problems/increasing-decreasing-string/submissions/310157784
*/

class Solution {
public:
    string sortString(string s) {
        map<char, int> mp;
        for(int i = 0;i<=25;i++){
            mp[char(i+'a')] = 0;
        }
        for(auto ch : s){
            mp[ch] += 1;
        }
        string res = "";
        char ch = 'a';
        int index = 0;
        while(res.size() < s.size()){
            if(index % 2 == 0){
                ch = 'a';
                while(ch <= 'z'){
                    if(mp[ch] > 0){
                        res += ch;
                        mp[ch] -= 1;
                    }
                    ch++;
                }
            
            }
            else{
                ch = 'z';
                while(ch >= 'a'){
                    if(mp[ch] > 0){
                        res += ch;
                        mp[ch] -= 1;
                    }
                    ch--;
                }
            }
            index += 1;
        }
        return res;
    }
};