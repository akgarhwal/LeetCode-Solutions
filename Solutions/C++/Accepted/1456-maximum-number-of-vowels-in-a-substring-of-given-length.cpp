/*
Problem Title: 1456 - Maximum Number of Vowels in a Substring of Given Length
Lang: C++
Runtime: 64 ms
Memory: 9.8 MB
Problem Url: https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length
Submission Url: https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/submissions/344193472
*/

class Solution {
public:
    bool is_vowel(char ch){
        if(ch == 'a' or ch == 'e' or ch =='i' or ch == 'o' or ch == 'u'){
            return true;
        }
        return false;
    }
    int maxVowels(string s, int k) {
        int f = 0, ss = 0;
        int ans = 0, count = 0;
        while(f < s.size()){
            
            while(ss-f < k and ss < s.size()){
                if(is_vowel(s[ss])){
                    count++;
                }
                ss++;
            }
            ans = max(ans, count);
            if(is_vowel(s[f])){
                count--;
            }
            f++;
        }
        return ans;
    }
};