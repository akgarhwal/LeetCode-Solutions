/*
Problem Title: 290 - Word Pattern
Lang: C++
Runtime: 0 ms
Memory: 6.3 MB
Problem Url: https://leetcode.com/problems/word-pattern
Submission Url: https://leetcode.com/problems/word-pattern/submissions/868755488
*/

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        string word = "";
        unordered_map<string,char> ht;
        unordered_map<char,string> ht2;
        int count = 0, wc =0;
        for(char ch : s) {
            if(ch == ' ') {
                if(ht.find(word) != ht.end()) {
                    if(ht[word] != pattern[count]) {
                        return false;
                    }
                } else if(ht2.find(pattern[count]) != ht2.end()) {
                    if(ht2[pattern[count]] != word) {
                        return false;
                    }
                } else {
                    ht[word] = pattern[count];
                    ht2[pattern[count]] = word;
                }
                
                word = "";
                count += 1;
                wc += 1;
            } else {
                word += ch;
            }
        }
        wc += 1;
        if(pattern.size() != wc){
            return false;
        }
        if(ht.find(word) != ht.end()) {
            if(ht[word] != pattern[count]) {
                return false;
            }
        }
        if(ht2.find(pattern[count]) != ht2.end()) {
            if(ht2[pattern[count]] != word) {
                return false;
            }
        }
        return true;
    }
};