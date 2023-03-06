/*
Problem Title: 1345 - Jump Game IV
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/jump-game-iv
Submission Url: https://leetcode.com/problems/jump-game-iv/submissions/909198893
*/

class Solution {
public:

    void solve(int index, vector<int>& arr, unordered_map<int, vector<int>>& ht, vector<int>& vis, int& level, int& ans) {
        if(index == arr.size()-1) {
            ans = min(level, ans);
            return;
        }
        // cout<<index<<" -> ";

        vis[index] = true;
        for(int x : ht[arr[index]]) {
            if(!vis[x]) {
                level += 1;
                solve(x, arr, ht, vis, level, ans);
                level -= 1;
            }
        }
        if(index < (arr.size()-1) and !vis[index+1]) {
            level += 1;
            solve(index+1, arr, ht, vis, level, ans);
            level -= 1;
        }

        if(index > 0 and !vis[index-1]) {
            level += 1;
            solve(index-1, arr, ht, vis, level, ans);
            level -= 1;
        }
    }


    int minJumps(vector<int>& arr) {
        vector<vector<int>> adj(arr.size());
        unordered_map<int, vector<int>> ht;

        for(int i=0; i < arr.size(); i++) {
            ht[arr[i]].push_back(i);
        }

        // for(auto pi : ht) {
        //     cout<<pi.first<<" => ";
        //     for(int x : pi.second) {
        //         cout<<x<<", ";
        //     }
        //     cout<<endl;
        // }
        
        vector<int> vis(arr.size(), false);
        int level = 0, ans = INT_MAX;

        solve(0, arr, ht, vis, level, ans);

        return ans;
    }
};