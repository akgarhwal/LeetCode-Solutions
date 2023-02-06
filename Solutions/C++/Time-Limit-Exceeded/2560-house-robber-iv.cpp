/*
Problem Title: 2560 - House Robber IV
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/house-robber-iv
Submission Url: https://leetcode.com/problems/house-robber-iv/submissions/891731541
*/

class Solution {
public:
    
    
    void print(set<pair<int,int>>& st) {
        for(auto pi : st) {
            cout<<pi.first<<","<<pi.second<<"   ";
        }
        cout<<endl;
    }
    
    void solve(int cur, int k, bool isLastRobbed, vector<int>& nums, set<pair<int,int>>& st, int& ans, unordered_map<string,int>& mp) {
        // if(mp.find(to_string(cur) + "-" + to_string(k)) != mp.end()) {
        //     return;
        // }
        if(k == 0){
            ans = min(ans, (*(st.rbegin())).first);
            // cout<<"Capability: "<<(*(st.rbegin())).first<<endl;
            mp[to_string(cur) + "-" + to_string(k)] = ans;
            return;
        }
        if(cur >= nums.size()) {
            return;
        }
        
        solve(cur+1, k, false, nums, st, ans, mp);
        
        if(isLastRobbed == false) {
            st.insert({nums[cur], cur});
            solve(cur+1, k-1, !isLastRobbed, nums, st, ans, mp);
            st.erase({nums[cur], cur});
        }
    }
    
    
    int minCapability(vector<int>& nums, int k) {
        int ans = INT_MAX;
        set<pair<int,int>> st; // {money, index} to make unique
        unordered_map<string,int> mp;
        solve(0, k, false, nums, st, ans, mp);
        
        return ans;
    }
};