/*
Problem Title: 451 - Sort Characters By Frequency
Lang: C++
Runtime: 48 ms
Memory: 8.6 MB
Problem Url: https://leetcode.com/problems/sort-characters-by-frequency
Submission Url: https://leetcode.com/problems/sort-characters-by-frequency/submissions/343096688
*/

bool comp(pair<char, int> p1, pair<char,int> p2){
    return p1.second > p2.second;
}
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(char ch : s){
            mp[ch]++;
        }
        vector<pair<char,int>> vi;
        for(auto it: mp){
            vi.push_back({it.first, it.second});
        }
        sort(vi.begin(), vi.end(), comp);
        string ans = "";
        for(auto pi : vi){
            int co = pi.second;
            while(co--){
                ans += pi.first;
            }
            
        }
        return ans;
    }
};