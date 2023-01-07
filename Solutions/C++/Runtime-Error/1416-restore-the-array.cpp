/*
Problem Title: 1416 - Restore The Array
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/restore-the-array
Submission Url: https://leetcode.com/problems/restore-the-array/submissions/326623869
*/

class Solution {
public:
    unordered_map<int, int> mp;
    int mod = 1e9+7;
    int fun(int pos, string& s, int k){
        if(pos == s.size()){
            return 1;
        }
        
        if(mp.find(pos) != mp.end()){
            return mp[pos];
        }
        
        if(s[pos] == '0'){
            return 0;
        }
        
        int ans = 0;
        int temp = 0;
        for(int i = pos; i< s.size(); i++ ){
                        
            temp = (temp*10) + (s[i]-'0');
            
            if(temp <= k){
                ans = (ans + fun(i + 1, s, k))%mod;
            }
            else{
                break;
            }
        }
        
        mp[pos] = ans;
        return ans;
    }
    
    
    int numberOfArrays(string s, int k) {
        
        
        return fun(0, s, k);
    }
};