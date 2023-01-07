/*
Problem Title: 205 - Isomorphic Strings
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/isomorphic-strings
Submission Url: https://leetcode.com/problems/isomorphic-strings/submissions/764667096
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp;
        for(int i = 0; i < s.size(); i++) {
            if( mp.find(s[i]) != mp.end() and mp[s[i]] != t[i]) {
                return false;
            } 
            // else if( mp.find(t[i]) != mp.end() and mp[t[i]] != s[i]) {
            //     return false;
            // }
            else {
                mp[s[i]] = t[i];
            }
        }
        return true;
    }
};