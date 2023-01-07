/*
Problem Title: 1540 - Can Convert String in K Moves
Lang: C++
Runtime: 612 ms
Memory: 32.1 MB
Problem Url: https://leetcode.com/problems/can-convert-string-in-k-moves
Submission Url: https://leetcode.com/problems/can-convert-string-in-k-moves/submissions/378292749
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
            int d2 = d;
            if(mp[d].size() == 0){
                mp[d].push_back(d);
            }
            else{
                d2 = mp[d][mp[d].size()-1] + 26;
                mp[d].push_back(d2);
            }
            if(d2 > k){
                return false;
            }
        }
        return true;
        
    }
};