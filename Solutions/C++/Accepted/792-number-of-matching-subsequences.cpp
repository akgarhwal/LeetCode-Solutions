/*
Problem Title: 792 - Number of Matching Subsequences
Lang: C++
Runtime: 385 ms
Memory: 49.9 MB
Problem Url: https://leetcode.com/problems/number-of-matching-subsequences
Submission Url: https://leetcode.com/problems/number-of-matching-subsequences/submissions/751572572
*/

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char, vector<int>> mp;
        for(int i = 0; i < s.size();i++){
            mp[s[i]].push_back(i);
        }
        int ans = 0;
        for(string word : words){
            int li = -1;
            bool found = true;
            for(char ch : word){
                int ub = upper_bound(mp[ch].begin(), mp[ch].end(), li) - mp[ch].begin();
                if(ub == mp[ch].size()){
                    found = false;
                    break;
                }
                li = mp[ch][ub];                
            }
            ans = found ? ans+1 : ans;            
        }
        return ans;
    }
};