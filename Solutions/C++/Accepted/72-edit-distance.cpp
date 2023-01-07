/*
Problem Title: 72 - Edit Distance
Lang: C++
Runtime: 1972 ms
Memory: 429.2 MB
Problem Url: https://leetcode.com/problems/edit-distance
Submission Url: https://leetcode.com/problems/edit-distance/submissions/347048533
*/

class Solution {
public:
    
    int helper(string s, string t,int a, int b, unordered_map<string, int>& mp){
        if(a == 0 or b == 0){
            return max(a,b);
        }
        
        string key = to_string(a)+"-"+to_string(b);
        
        if(mp.find(key) != mp.end()){
            return mp[key];
        }
        
        int d1 = helper(s,t,a-1,b-1, mp) + (s[a-1] == t[b-1] ? 0 : 1);
        
        int d2 = helper(s,t,a,b-1, mp) + 1;
        
        int d3 = helper(s,t,a-1,b, mp) + 1;
        
        
        return mp[key] = min({d1,d2,d3});
    }
    
    int minDistance(string word1, string word2) {
        unordered_map<string, int> mp;
        return helper(word1, word2, word1.size(),word2.size(), mp);
    }
};