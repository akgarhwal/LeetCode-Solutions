/*
Problem Title: 290 - Word Pattern
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/word-pattern
Submission Url: https://leetcode.com/problems/word-pattern/submissions/868754346
*/

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        string word = "";
        unordered_map<string,char> ht;
        unordered_map<char,string> ht2;
        int count = 0;
        for(char ch : s) {
            if(ch == ' '){
                cout<<word<<" - "<<count<<endl;
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
            } else {
                word += ch;
            }
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