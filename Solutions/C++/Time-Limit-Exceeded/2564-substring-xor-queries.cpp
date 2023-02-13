/*
Problem Title: 2564 - Substring XOR Queries
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/substring-xor-queries
Submission Url: https://leetcode.com/problems/substring-xor-queries/submissions/896311949
*/

class Solution {
public:
    
    string intToBinaryString(int n) {
        string result = "";
        while(n > 0) {
            result += (n&1) ? '1' : '0';
            n = n >> 1;
        }
        if(result.size() == 0){
            return "0";
        }
        reverse(result.begin(), result.end());
        return result;
    }
    
    int findSubString(string main, string target){
        for(int i=0; i < main.size(); i++) {
            int j = 0;
            for(; j < target.size(); j++) {
                if(main[i+j] != target[j]){
                    break;
                }
            }
            if(j == target.size()){
                return i;
            }
        }
        return -1;
    }
    
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        vector<vector<int>> ans(queries.size(), vector<int>(2, -1));
        int ind = 0;
        unordered_map<int,pair<int,int>> mp;
        
        
        for(auto query: queries) {
            int x = query[0]^query[1];
            int pos = -1, sz = 0;
            if(mp.find(x) != mp.end()) {
                pos = mp[x].first;
                sz = mp[x].second;
            } else {
                string binaryX = intToBinaryString(x);
                pos = findSubString(s, binaryX);
                sz = binaryX.size();
                mp[x] = {pos, sz};
            }
        
            
            if(pos != -1){
                ans[ind][0] = pos;
                ans[ind][1] = pos + sz - 1;
            }
            ind++;
        }
        return ans;
    }
};