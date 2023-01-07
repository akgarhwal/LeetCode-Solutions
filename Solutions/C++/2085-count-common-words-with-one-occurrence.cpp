/*
Problem Title: 2085 - Count Common Words With One Occurrence
Lang: C++
Runtime: 36 ms
Memory: 20.1 MB
Problem Url: https://leetcode.com/problems/count-common-words-with-one-occurrence
Submission Url: https://leetcode.com/problems/count-common-words-with-one-occurrence/submissions/593424449
*/

class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> mp1, mp2;
        
        for(string x : words1){
            mp1[x] += 1;
        }
        for(string x : words2){
            mp2[x] += 1;
        }
        int ans = 0;
        for(auto x : mp1){
            if (mp1[x.first] == 1 and mp2[x.first] == 1){
                ans++;
            }
        }
        return ans;
    }
};