/*
Problem Title: 472 - Concatenated Words
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/concatenated-words
Submission Url: https://leetcode.com/problems/concatenated-words/submissions/886049263
*/

class Solution {
public:

    bool solve(int count, string word, unordered_set<string>& ht) {
        if(word.size() == 0){
            return true and  count > 1;
        }
        cout<<word<<endl;
        bool res = false;
        // string prefix = "";
        for(int i=0; i < word.size(); i++) {
            prefix += word[i];
            if(ht.find(prefix) != ht.end()) {
                res = res or solve(count+1, word.substr(i+1), ht);
            }
            // cout<<" ==== \n";
        }
        return res;
    } 

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> ht;
        for(string word : words){
            ht.insert(word);
        }

        vector<string> result;

        for(string word : words){
            // cout<<" -------- \n";
            bool res = solve(0, word, ht);
            if(res){
                result.push_back(word);
            }
        }
        return result;
    }
};