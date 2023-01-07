/*
Problem Title: 890 - Find and Replace Pattern
Lang: C++
Runtime: 11 ms
Memory: 8.5 MB
Problem Url: https://leetcode.com/problems/find-and-replace-pattern
Submission Url: https://leetcode.com/problems/find-and-replace-pattern/submissions/759572107
*/

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        
        for(string word : words) {
            
            if(same(word, pattern)){
                ans.push_back(word);
            }
            
        }
        return ans;
    }
    
    bool same(string word, string pattern){
        bool isSame = true;
        for(int i=0;i<pattern.size();i++){
            
            vector<int> pi = findSameCharInd(pattern, i);
            vector<int> wi = findSameCharInd(word, i);
                
            if(pi.size() != wi.size()){
                isSame = false;
                break;
            }
            for(int j=0; j < pi.size();j++){
                if(pi[j] != wi[j]){
                    isSame = false;
                    break;
                }
            }
            
        }
        
        return isSame;
    }
    
    vector<int> findSameCharInd(string str, int x){
        vector<int> inds;
        for(int i = 0; i<str.size();i++){
            if(str[i] == str[x]){
                inds.push_back(i);
            }
        }
        return inds;
    }
};