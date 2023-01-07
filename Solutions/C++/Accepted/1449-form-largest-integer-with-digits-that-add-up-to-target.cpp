/*
Problem Title: 1449 - Form Largest Integer With Digits That Add up to Target
Lang: C++
Runtime: 636 ms
Memory: 533.1 MB
Problem Url: https://leetcode.com/problems/form-largest-integer-with-digits-that-add-up-to-target
Submission Url: https://leetcode.com/problems/form-largest-integer-with-digits-that-add-up-to-target/submissions/340221436
*/

class Solution {
    unordered_map<int, string> mp;
    string ans="";
public:
    
    string MAX(string s1, string s2){
        if(s1.size() > s2.size()){
            return s1;
        }
        else if (s1.size() < s2.size()){
            return s2;
        }
        else if(s1 > s2){
            return s1;
        }
        return s2;
    }
    
    
    string helper(string cur, int target,vector<int>& cost){
        
        if(target == 0){
            return cur;
        }
        
        if(mp.find(target) != mp.end() and mp[target] == ""){
            
            return "";
            
        }
        
        if(mp.find(target) != mp.end() ){
            return cur + mp[target];
        }
        string ans = "";
        
        for(int i = 8; i>=0; i--){
            if(cost[i] <= target){
                string s2 = helper(to_string(i+1), target-cost[i], cost);
                ans = MAX(ans, s2);
            }
        }
        
        if(ans == ""){
            mp[target] = ans;
            return "";
        }
        mp[target] = ans;
        return  cur + ans;
    }
    
    
    string largestNumber(vector<int>& cost, int target) {
        ans = "0";
        ans = MAX(ans, helper("", target, cost));
        return ans == "" ? "0":ans;
    }
};