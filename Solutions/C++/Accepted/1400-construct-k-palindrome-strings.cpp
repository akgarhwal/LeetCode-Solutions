/*
Problem Title: 1400 - Construct K Palindrome Strings
Lang: C++
Runtime: 44 ms
Memory: 11.9 MB
Problem Url: https://leetcode.com/problems/construct-k-palindrome-strings
Submission Url: https://leetcode.com/problems/construct-k-palindrome-strings/submissions/322995327
*/

class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.size() < k){
            return false;
        }
        vector<int> fr(26, 0);
        for(char ch : s){
            fr[ch-'a'] += 1;
        }
        
        int odd_count = 0;
        for(int x : fr){
            if(x % 2 == 1){
                odd_count += 1;
            }
        }
        if(odd_count > k){
            return false;
        }
        
        return true;
    }
};