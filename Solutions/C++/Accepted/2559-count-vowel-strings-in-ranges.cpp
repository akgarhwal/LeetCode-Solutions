/*
Problem Title: 2559 - Count Vowel Strings in Ranges
Lang: C++
Runtime: 170 ms
Memory: 68.7 MB
Problem Url: https://leetcode.com/problems/count-vowel-strings-in-ranges
Submission Url: https://leetcode.com/problems/count-vowel-strings-in-ranges/submissions/891698840
*/

class Solution {
public:
    
    bool isStartAndEndWithzVowel(string word) {
        
        char lastChar = word[word.size()-1];
        
        if ( (word[0] == 'a' or word[0] == 'e' or word[0] == 'i' or word[0] == 'o' or word[0] == 'u') and (lastChar == 'a' or lastChar == 'e' or lastChar == 'i' or lastChar == 'o' or lastChar == 'u') ) { 
            return true;
        }
        return false;
    }
    
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> ans(words.size(), 0);
        int count = 0;
        for(int i = 0; i < words.size(); i++) {
            string word = words[i];
            if(isStartAndEndWithzVowel(words[i])) {
                count++;
            }
            ans[i] = count;
        }
        
        vector<int> result;
        
        for(vector<int> query : queries) {
            if(query[0] == 0){
                result.push_back(ans[query[1]]);
            } else {
                result.push_back(ans[query[1]] - ans[query[0]-1]);
            }
        }
        
        return result;
    }
};