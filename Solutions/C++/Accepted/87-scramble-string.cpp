/*
Problem Title: 87 - Scramble String
Lang: C++
Runtime: 179 ms
Memory: 37.3 MB
Problem Url: https://leetcode.com/problems/scramble-string
Submission Url: https://leetcode.com/problems/scramble-string/submissions/924915404
*/

class Solution {
public:

    bool solve(string s1, string s2, unordered_map<string, bool>& mp) {
        if(s1 == s2) {
            return true;
        }

        if(s1.size() != s2.size()) {
            return false;
        }

        string key = s1 + "-" + s2;
        if(mp.find(key) != mp.end()) {
            return mp[key];
        }

        bool result = false;
        int n = s1.size();
        for(int i = 1; i < n; i++) {

            bool swapped = solve(s1.substr(0, i), s2.substr(n-i, i), mp) &&
                           solve(s1.substr(i, n-i), s2.substr(0, n-i), mp);
            if(swapped) {
                result = true;
                break;
            }

            bool not_swapped = solve(s1.substr(0, i), s2.substr(0, i), mp) &&
                               solve(s1.substr(i, n-i), s2.substr(i, n-i), mp);
            if(not_swapped) {
                result = true;
                break;
            }
        }

        return mp[key] = result;
    }


    bool isScramble(string s1, string s2) {
        unordered_map<string, bool> mp;
        return solve(s1, s2, mp);
    }
};