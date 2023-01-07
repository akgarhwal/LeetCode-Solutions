/*
Problem Title: 1910 - Remove All Occurrences of a Substring
Lang: C++
Runtime: 4 ms
Memory: 8 MB
Problem Url: https://leetcode.com/problems/remove-all-occurrences-of-a-substring
Submission Url: https://leetcode.com/problems/remove-all-occurrences-of-a-substring/submissions/513756180
*/

class Solution {
public:
    string removeOccurrences(string s, string part) {
        int pos = s.find(part);
        while(pos  != -1){
            s  = s.substr(0,pos) + s.substr(pos+(int)part.size());
            pos = s.find(part);
        }
        return s;
    }
};