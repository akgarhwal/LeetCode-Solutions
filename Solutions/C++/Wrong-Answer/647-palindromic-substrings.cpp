/*
Problem Title: 647 - Palindromic Substrings
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/palindromic-substrings
Submission Url: https://leetcode.com/problems/palindromic-substrings/submissions/308674047
*/

class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        int ind = 0;
        while(ind  < s.size()){
            int i = ind, j = ind;
            while( i >= 0 && j < s.size() && s[i] == s[j]){
                ans += 1;
                i--;
                j++;
            }
            ind += 1;
        }
        return ans;        
    }
};