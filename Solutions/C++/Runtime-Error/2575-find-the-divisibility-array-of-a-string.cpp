/*
Problem Title: 2575 - Find the Divisibility Array of a String
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/find-the-divisibility-array-of-a-string
Submission Url: https://leetcode.com/problems/find-the-divisibility-array-of-a-string/submissions/905017380
*/

class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int> ans(word.size(), 0);
        long long rem = 0;
        long long temp = 0;
        for(int i = 0; i < word.size(); i++) {
            temp = temp * 10 + (word[i] - '0') + rem;
            long long tempRem = temp%m;
            
            if( tempRem == 0 ) {
                ans[i] = 1;
                rem = 0;
                temp = 0;
            }
        }
        
        return ans;
    }
};