/*
Problem Title: 49 - Group Anagrams
Lang: C++
Runtime: 120 ms
Memory: 17.8 MB
Problem Url: https://leetcode.com/problems/group-anagrams
Submission Url: https://leetcode.com/problems/group-anagrams/submissions/320621156
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> res;
        for(auto str : strs){
            string hc = str;
            sort(hc.begin(), hc.end());
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