/*
Problem Title: 520 - Detect Capital
Lang: C++
Runtime: 0 ms
Memory: 6.2 MB
Problem Url: https://leetcode.com/problems/detect-capital
Submission Url: https://leetcode.com/problems/detect-capital/submissions/869390064
*/

class Solution {
public:
    bool allCaps(string word) {
        for(int i = 0; i < word.size(); i++) {
            if(!(word[i] >= 'A' and word[i] <= 'Z')) {
                return false;
            }
        }
        return true;
    }
    bool allSmall(string word) {
        for(int i = 0; i < word.size(); i++) {
            if(!(word[i] >= 'a' and word[i] <= 'z')) {
                return false;
            }
        }
        return true;
    }

    bool detectCapitalUse(string word) {
        bool ans = allCaps(word);
        ans = ans or allSmall(word);
        ans = ans or ((word[0] >= 'A' and word[0] <= 'Z') and allSmall(word.substr(1)));
        return ans;
    }
};