/*
Problem Title: 1540 - Can Convert String in K Moves
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/can-convert-string-in-k-moves
Submission Url: https://leetcode.com/problems/can-convert-string-in-k-moves/submissions/378291977
*/

class Solution {
public:
    bool canConvertString(string s, string t, int k) {
  
        map<int, vector<int>> mp;
        
        if(s.size() != t.size()){
            return false;
        }
        
        for(int i = 0; i< s.size(); i++){
            
            
            int d = t[i]  - s[i];
            if(d < 0){
                d += 26;
            }
            if(d == 0){
                continue;
            }
            if(mp[d].size() == 0){
                mp[d].push_back(d);
            }
            else{
                d = mp[d][mp[d].size()-1];
                mp[d].push_back(d + 26);
            }
            if(d > k){
                return false;
            }
        }
        return true;
        
    }
};