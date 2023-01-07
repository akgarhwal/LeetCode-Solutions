/*
Problem Title: 1451 - Rearrange Words in a Sentence
Lang: C++
Runtime: 164 ms
Memory: 19.3 MB
Problem Url: https://leetcode.com/problems/rearrange-words-in-a-sentence
Submission Url: https://leetcode.com/problems/rearrange-words-in-a-sentence/submissions/340481782
*/

class Solution {
public:
    string arrangeWords(string text) {
        map<int, vector<string>> store;
        string word = "";
        for(char ch : text){
            if(ch == ' '){
                store[word.size()].push_back(word);
                word = "";
            }
            else{
                if(ch >= 65 and ch <= 91){
                    ch = ch + 32;
                }
                word += ch;
            }
        }
        store[word.size()].push_back(word);
        string ans = "";
        for(auto it : store){
            for(int i=0; i < it.second.size(); i++){
                ans += it.second[i] + ' ';
            }
        }
        ans[0] = ans[0] - 32;
        string fin(ans.begin(), ans.end()-1);
        return fin;
    }
};