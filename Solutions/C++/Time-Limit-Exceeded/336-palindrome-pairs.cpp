/*
Problem Title: 336 - Palindrome Pairs
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/palindrome-pairs
Submission Url: https://leetcode.com/problems/palindrome-pairs/submissions/507304506
*/

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<pair<string,int>> swords;
        int is_e = -1;
        for(int i=0;i<words.size();i++){
            string temp = words[i];
            reverse(temp.begin(), temp.end());
            swords.push_back({temp, i});
            if(words[i].size() == 0){
                is_e = i;
            }
        }
        
        set<pair<int,int>> st;
        
        sort(swords.begin(), swords.end());
        
        vector<vector<int>> ans;
        
        for(int i=0;i<words.size();i++){
            
            int idx = bs(swords, words[i]);
            
            //cout<<words[i]<<" --> "<<idx<<endl;
            
            while( idx != -1 and idx < swords.size() and swords[idx].first[0] == words[i][0]){
                
                //cout<<i<<" - "<<swords[idx].first.substr(0, words[i].size())<<endl;
                
                if(i != swords[idx].second and isPalin(words[i]+words[swords[idx].second])){
                    vector<int> pair;
                    pair.push_back(i);
                    pair.push_back(swords[idx].second);
                    st.insert({i, swords[idx].second});
                }
                if(i != swords[idx].second and isPalin(words[swords[idx].second]+words[i])){
                    vector<int> pair;
                    pair.push_back(i);
                    pair.push_back(swords[idx].second);
                    st.insert({swords[idx].second,i});
                }
                idx += 1;
            }
//             string w2 = words[i].substr(0, words[i].size()-1);
//             idx = bs(swords, w2);
            
//             if(w2.size() > 0 ){
//                 //cout<<words[i]<<" -- "<<idx<<endl;
//                 while( idx != -1 and idx < swords.size() and swords[idx].first[0] == w2[0]){
//                     // cout<<i<<" - "<<swords[idx].first.substr(0,w2.size())<<endl;
//                     if(i != swords[idx].second and isPalin(words[i]+words[swords[idx].second])){
//                         vector<int> pair;
//                         pair.push_back(i);
//                         pair.push_back(swords[idx].second);
//                         st.insert({i, swords[idx].second});
//                     }
                    
//                     idx += 1;
//                 }
//             }
            
            
            
            if(is_e != -1 and i!= is_e and isPalin(words[i])){
                vector<int> pair;
                pair.push_back(i);
                pair.push_back(is_e);
                st.insert({i, is_e});
                st.insert({is_e, i});
            }
            
        }
        
        for(auto e : st){
            vector<int> pair(2);
            pair[0] = e.first;
            pair[1] = e.second;
            ans.push_back(pair);
        }
        
        return ans;
    }
    
    int bs(vector<pair<string,int>> &swords, string word){
        
        int st = 0,end = swords.size()-1;
        int ans = -1;
        while(st <= end){
            int mid = st + (end-st)/2;
            
            if(swords[mid].first[0] >= word[0]){
                ans = mid;
                end = mid-1;
            }
            else{
                st = mid+1;
            }
        }
        return ans;        
    }
    
    bool isPalin(string s){
        int n = s.size();
        for(int i=0;i < n/2;i++){
            if(s[i] != s[n-1-i]){
                return false;
            }
        }
        return true;
    }
    
};