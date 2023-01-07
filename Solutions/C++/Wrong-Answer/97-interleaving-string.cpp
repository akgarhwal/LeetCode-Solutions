/*
Problem Title: 97 - Interleaving String
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/interleaving-string
Submission Url: https://leetcode.com/problems/interleaving-string/submissions/501807914
*/

class Solution {
public:
    
    bool isValid(string s1, string s2, string s3, int i, int j, int k){
        if(k == s3.size()){
            return true;
        }
        bool res = true;
        
        if(s1[i] == s2[j] and s1[i] == s3[k]){
            
            bool temp = isValid(s1,s2,s3,i+1, j, k+1);
            
            if(!temp){
                res = res and isValid(s1,s2,s3,i, j+1, k+1);   
            }   
        }
        return res;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()){ 
            return false;
        }
        
        return isValid(s1,s2,s3,0,0,0);
    }
};