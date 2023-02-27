/*
Problem Title: 2575 - Find the Divisibility Array of a String
Lang: C++
Runtime: 64 ms
Memory: 21.6 MB
Problem Url: https://leetcode.com/problems/find-the-divisibility-array-of-a-string
Submission Url: https://leetcode.com/problems/find-the-divisibility-array-of-a-string/submissions/905023186
*/

class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int> ans(word.size(), 0);
        long long temp = 0;
        
        for(int i = 0; i < word.size(); i++) {
            temp = temp * 10 + (word[i] - '0');
            
            long long tempRem = temp%m;
            
            if( tempRem == 0 ) {
                ans[i] = 1;
                temp = 0;
            } else {
                temp = tempRem;
            }
        }
        
        return ans;
    }
};