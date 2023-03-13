/*
Problem Title: 2586 - Count the Number of Vowel Strings in Range
Lang: C++
Runtime: 16 ms
Memory: 31.7 MB
Problem Url: https://leetcode.com/problems/count-the-number-of-vowel-strings-in-range
Submission Url: https://leetcode.com/problems/count-the-number-of-vowel-strings-in-range/submissions/913606092
*/

class Solution {
public:
    bool is_vowel(char ch){
        return (ch == 'a' or ch == 'e' or ch == 'o' or ch == 'i' or ch == 'u');
    }
    int vowelStrings(vector<string>& words, int left, int right) {
        int ans = 0;
        for(int i = left; i <= right; i++) {
            if(is_vowel(words[i][0]) and is_vowel(words[i][words[i].size()-1])) {
                ans += 1;
            }
        }
        return ans;
    }
};