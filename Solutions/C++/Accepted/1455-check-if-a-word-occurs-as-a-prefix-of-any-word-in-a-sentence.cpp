/*
Problem Title: 1455 - Check If a Word Occurs As a Prefix of Any Word in a Sentence
Lang: C++
Runtime: 0 ms
Memory: 6.3 MB
Problem Url: https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence
Submission Url: https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/submissions/344191876
*/

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int ans = -1;
        
        int i = 0, j=0, ss = 1, co = 0;
        while( i< sentence.size()){
            
            if(sentence[i] == ' '){
                j = 0;
                ss = 1;
                co++;
            }
            else if(ss == 1 and sentence[i] == searchWord[j]){
                j++;
            }
            else{
                ss = 0;
            }
            if(j == searchWord.size())
            {
                ans = co+1;
                break;
            }            
            i++;
        }
        return ans;
    }
};