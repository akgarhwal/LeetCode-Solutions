/*
Problem Title: 1374 - Generate a String With Characters That Have Odd Counts
Lang: C++
Runtime: 0 ms
Memory: 7.9 MB
Problem Url: https://leetcode.com/problems/generate-a-string-with-characters-that-have-odd-counts
Submission Url: https://leetcode.com/problems/generate-a-string-with-characters-that-have-odd-counts/submissions/310346101
*/

class Solution {
public:
    string generateTheString(int n) {
        string ans(n,'a');
        if(n%2==0){
            ans[n-1] = 'b';
        }
        return ans;
    }
};