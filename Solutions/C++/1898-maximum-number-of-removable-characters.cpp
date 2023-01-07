/*
Problem Title: 1898 - Maximum Number of Removable Characters
Lang: C++
Runtime: 324 ms
Memory: 90.2 MB
Problem Url: https://leetcode.com/problems/maximum-number-of-removable-characters
Submission Url: https://leetcode.com/problems/maximum-number-of-removable-characters/submissions/507089962
*/

class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        
        int ans = 0;
        
        int st = 0, end = removable.size()-1;
        
        while(st <= end){
            
            int mid = st + (end-st)/2;
            
            bool res = isSeq(mid, s, p, removable);
            
            if(res){
                ans = max(ans, mid+1);
                st = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        
        return ans;        
        
    }
    
    
    bool isSeq(int mid, string s, string &p, vector<int>& removable){
        
        for(int i = 0 ; i <= mid; i++){
            s[removable[i]] = '-';
        }
        
        int x = 0, y = 0;
        
        while(x < s.size()){
            if(s[x] == p[y]){
                y++;
            }
            if(y == p.size()){
                return true;
            }
            x++;    
        }
       
        return false;
    }
    
    
};