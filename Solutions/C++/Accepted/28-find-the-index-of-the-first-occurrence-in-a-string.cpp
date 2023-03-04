/*
Problem Title: 28 - Find the Index of the First Occurrence in a String
Lang: C++
Runtime: 0 ms
Memory: 6.3 MB
Problem Url: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string
Submission Url: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/submissions/908026596
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i = 0; i < haystack.size(); i++){

            int j = 0;
            while(j < needle.size() and haystack[i+j] == needle[j]) {
                j++;
            }

            if(j == needle.size()) {
                return i;
            }
        }

        return -1;
    }
};