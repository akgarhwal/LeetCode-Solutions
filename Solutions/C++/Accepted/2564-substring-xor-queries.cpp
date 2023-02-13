/*
Problem Title: 2564 - Substring XOR Queries
Lang: C++
Runtime: 457 ms
Memory: 113.2 MB
Problem Url: https://leetcode.com/problems/substring-xor-queries
Submission Url: https://leetcode.com/problems/substring-xor-queries/submissions/896366901
*/

class Solution {
public:
    
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        vector<vector<int>> ans(queries.size(), vector<int>(2, -1));
        int ind = 0;
        unordered_map<int, pair<int,int>> mp;
         
        for(int i = 0; i < s.size(); i++) {
            string temp = "";
            int val = 0;
            
            if(mp.count(0) == 0 and s[i] == '0') {
                mp[0] = {i, i};
            }
            
            if(s[i] == '0') {
                continue;
            }
            for(int j = i; j < min((int)s.size(), i+31); j++) {
                
                temp += s[j];
                val = val * 2 + ((s[j] == '1') ? 1 : 0);
                
                if(mp.count(val) == 0 and s[i] != '0') {
                    mp[val] = {i, j};
                }
            }
            
        }
        
        for(auto query: queries) {
            
            int x = query[0]^query[1];
            if(mp.count(x)) {
                ans[ind][0] = mp[x].first;
                ans[ind][1] = mp[x].second;
            }
            ind++;
        }
        return ans;
    }
};