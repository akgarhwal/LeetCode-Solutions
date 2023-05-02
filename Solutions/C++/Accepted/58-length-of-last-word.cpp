/*
Problem Title: 58 - Length of Last Word
Lang: C++
Runtime: 5 ms
Memory: 6.5 MB
Problem Url: https://leetcode.com/problems/length-of-last-word
Submission Url: https://leetcode.com/problems/length-of-last-word/submissions/942463547
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0, count = 0;

        for(char ch : s) {
            if(ch == ' ') {
                if(count > 0) {
                    ans = count;
                }
                count = 0;
            } else {
                count += 1;
            }
        }
        if(count > 0) {
            ans = count;
        }
        return ans;
    }
};