/*
Problem Title: 1813 - Sentence Similarity III
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/sentence-similarity-iii
Submission Url: https://leetcode.com/problems/sentence-similarity-iii/submissions/475932258
*/

class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        
        if(s1 == s2) {
            return true;
        }
        if(s1.size() < s2.size()){
            string temp = s1;
            s1= s2;
            s2 =temp;
        }
        int i = 0;
        if(s2 == s1.substr(s1.size()-s2.size(), s2.size())) {
            return true;
        }
        for(;i<s1.size();i++){
            
            if(s1[i] == ' '){
                
                if(s2.size() < i){
                    break;
                }
                    
                if(s2.substr(0,i) == s1.substr(0,i)  and s2.size() == i){
                    return true;
                }
                
                if(s2.substr(0,i) == s1.substr(0,i)  and s2.substr(i+1, s2.size()-i-1) == s1.substr(s1.size()-s2.size()+i+1, s2.size()-i-1)) {
                    return true;
                }
                
            }
            
        }
        
        return false;
    }
};