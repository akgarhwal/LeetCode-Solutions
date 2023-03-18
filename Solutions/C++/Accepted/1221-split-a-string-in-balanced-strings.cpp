/*
Problem Title: 1221 - Split a String in Balanced Strings
Lang: C++
Runtime: 3 ms
Memory: 6.2 MB
Problem Url: https://leetcode.com/problems/split-a-string-in-balanced-strings
Submission Url: https://leetcode.com/problems/split-a-string-in-balanced-strings/submissions/916600954
*/

class Solution {
public:
    int balancedStringSplit(string s) {
        int ans = 0, count = 0;

        for(int i = 0; i < s.size(); i++ ) {
            if(s[i] == 'R') {
                count += 1;
            } else {
                count -= 1;
            }
            if(count == 0){
                ans += 1;
            }
        }

        return ans;
    }
};