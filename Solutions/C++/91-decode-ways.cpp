/*
Problem Title: 91 - Decode Ways
Lang: C++
Runtime: 8 ms
Memory: 8.4 MB
Problem Url: https://leetcode.com/problems/decode-ways
Submission Url: https://leetcode.com/problems/decode-ways/submissions/434738033
*/

class Solution {
public:
    int numDecodings(string s) {
        unordered_map<int,int> mem;
        return decode(s,0,mem);
    }
    int decode(string s, int pos, unordered_map<int,int>& mem) {
        if(mem.find(pos) != mem.end()){
            return mem[pos];
        }
        if(pos == s.size()) return 1;
        if(pos == s.size()-1){
            return s[pos] == '0' ? 0 : 1;
        }
        int x = s[pos] - '0',ans = 0, y = s[pos+1] - '0';
        if(x > 0){
            ans = decode(s, pos+1, mem);
        }
        if( x > 0 and (x*10+y) < 27){
            ans += decode(s, pos+2, mem);
        }
        return mem[pos] = ans;
    }
};