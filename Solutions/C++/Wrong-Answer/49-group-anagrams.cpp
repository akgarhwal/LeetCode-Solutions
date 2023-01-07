/*
Problem Title: 49 - Group Anagrams
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/group-anagrams
Submission Url: https://leetcode.com/problems/group-anagrams/submissions/309321483
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<int,vector<string>> res;
        
        for(auto str : strs){
            int hc = 0;
            for(auto ch : str){
                hc = hc | (1 << (ch - 'a'));
            }
            if(res.count(hc) == 0){
                res[hc] = vector<string>(1, str);
            }
            else{
                res[hc].push_back(str);
            }
        }
        
        vector<vector<string>> ans;
        for(auto pi : res){
            ans.push_back(pi.second);
        }
        return ans;
    }
};