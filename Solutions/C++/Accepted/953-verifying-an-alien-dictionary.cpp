/*
Problem Title: 953 - Verifying an Alien Dictionary
Lang: C++
Runtime: 36 ms
Memory: 17.1 MB
Problem Url: https://leetcode.com/problems/verifying-an-alien-dictionary
Submission Url: https://leetcode.com/problems/verifying-an-alien-dictionary/submissions/889764493
*/

class Solution {
public:

    bool compare(string a, string b, string order) {
        int n = min(a.size(), b.size());
        for(int i = 0 ; i < n; i ++){
            int inda = order.find(a[i]);
            int indb = order.find(b[i]);
            if(a[i] != b[i]) {
                return inda < indb;
            }
            if(inda > indb ) {
                return false;
            }
        }
        if(a.size() > b.size()) {
            if(a.substr(0,n) == b.substr(0,n)) {
                return false;
            }
        }
        return true;
    }

    bool isAlienSorted(vector<string>& words, string order) {
        vector<string> newWords(words.begin(), words.end());

        sort(newWords.begin(), newWords.end(), [this, order](string a, string b){
            if(compare(a, b, order)){
                return true;
            }
            return false;
        });

        for(int i = 0; i < words.size(); i++) {
            if(words[i]  != newWords[i]) {
                return false;
            }
        }
        return true;
    }
};