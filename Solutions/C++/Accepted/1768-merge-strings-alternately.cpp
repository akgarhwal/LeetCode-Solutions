/*
Problem Title: 1768 - Merge Strings Alternately
Lang: C++
Runtime: 2 ms
Memory: 6.3 MB
Problem Url: https://leetcode.com/problems/merge-strings-alternately
Submission Url: https://leetcode.com/problems/merge-strings-alternately/submissions/935523425
*/

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";

        int i = 0, j =0;
        while( i < word1.size() or j < word2.size()) {
            if(i < word1.size()) {
                ans += word1[i++];
            }
            if( j < word2.size()) {
                ans += word2[j++];
            }
        }

        return ans;
    }
};