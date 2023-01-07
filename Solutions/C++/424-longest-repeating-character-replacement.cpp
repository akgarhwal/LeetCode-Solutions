/*
Problem Title: 424 - Longest Repeating Character Replacement
Lang: C++
Runtime: 50 ms
Memory: 7.1 MB
Problem Url: https://leetcode.com/problems/longest-repeating-character-replacement
Submission Url: https://leetcode.com/problems/longest-repeating-character-replacement/submissions/775143284
*/

class Solution {
public:
    bool isOkay(unordered_map<char, int> &mp, char ch, int k) {
        
        int mx = 0, count = 0;
        
        mp[ch] += 1;
        for(auto ele : mp){
            mx = max(mx, ele.second);
            count += ele.second;
        }
        mp[ch] -= 1;
        return count-mx <= k;
    }
    
    int characterReplacement(string s, int k) {
        int first = 0, second = 0;
        unordered_map<char, int> mp;
        
        int ans = 0;
        
        while(first < s.size()) {
            
            while(second < s.size() and isOkay(mp, s[second], k)) {
                
                mp[s[second]] += 1;
                second++;
            }
            
            ans = max(ans, second-first);
            mp[s[first]] -= 1;
            first++;
        }
        
        return ans;
    }
};