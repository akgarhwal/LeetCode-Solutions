/*
Problem Title: 14 - Longest Common Prefix
Lang: C++
Runtime: 7 ms
Memory: 9.9 MB
Problem Url: https://leetcode.com/problems/longest-common-prefix
Submission Url: https://leetcode.com/problems/longest-common-prefix/submissions/776653782
*/

class Solution {
public:
    string findCommonPrefix(string s1, string s2) {
        
        string ans = "";
        
        for(int i = 0; i < min(s1.size(), s2.size()); i++) {
            if(s1[i] == s2[i]){
                ans += s1[i];
            }
            else{
                break;
            }
        }
        return ans;
    }
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        
        for(string str : strs){
            ans = findCommonPrefix(ans, str);
        }
        
        return ans;
    }
};