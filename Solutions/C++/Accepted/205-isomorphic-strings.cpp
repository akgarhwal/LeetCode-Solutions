/*
Problem Title: 205 - Isomorphic Strings
Lang: C++
Runtime: 12 ms
Memory: 7.1 MB
Problem Url: https://leetcode.com/problems/isomorphic-strings
Submission Url: https://leetcode.com/problems/isomorphic-strings/submissions/764672407
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp, mp2;
        for(int i = 0; i < s.size(); i++) {
            if( mp.find(t[i]) != mp.end() and mp[t[i]] != s[i]) {
                return false;
            }
            else if( mp2.find(s[i]) != mp2.end() and mp2[s[i]] != t[i]) {
                return false;
            }
            else {
                mp[t[i]] = s[i];
                mp2[s[i]] = t[i];
            }
        }
        return true;
    }
};