/*
Problem Title: 2114 - Maximum Number of Words Found in Sentences
Lang: C++
Runtime: 12 ms
Memory: 10.6 MB
Problem Url: https://leetcode.com/problems/maximum-number-of-words-found-in-sentences
Submission Url: https://leetcode.com/problems/maximum-number-of-words-found-in-sentences/submissions/884487299
*/

class Solution {
public:
    int countWords(string sentence) {
        int wordCount = 1;
        for(char ch : sentence) {
            if(ch == ' '){
                wordCount += 1;
            }
        }
        return wordCount;
    }
    int mostWordsFound(vector<string>& sentences) {
        int ans = 0;
        for(string sentence : sentences) {
            ans = max(ans, countWords(sentence));
        }
        return ans;
    }
};