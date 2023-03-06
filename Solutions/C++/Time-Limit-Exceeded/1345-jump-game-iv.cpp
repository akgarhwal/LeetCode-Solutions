/*
Problem Title: 1345 - Jump Game IV
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/jump-game-iv
Submission Url: https://leetcode.com/problems/jump-game-iv/submissions/909201759
*/

class Solution {
public:

    int solve(int index, vector<int>& arr, unordered_map<int, vector<int>>& ht, vector<int>& vis) {
        int n = arr.size();
        queue<int>q;
        q.push(0);
        int steps = 0;
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                int curr = q.front(); q.pop();
                if (curr == n - 1) {
                    return steps;
                }
                if (curr + 1 < n && !vis[curr + 1]) {
                    vis[curr + 1] = true;
                    q.push(curr + 1);
                }
                if (curr - 1 >= 0 && !vis[curr - 1]) {
                    vis[curr - 1] = true;
                    q.push(curr - 1);
                }
                for (int newIdx : ht[arr[curr]]) {                                 
                    if (!vis[newIdx]) {
                        vis[newIdx] = true;
                        q.push(newIdx);
                    }
                }
            }
            steps++;
        }
        return -1;
    }


    int minJumps(vector<int>& arr) {
        vector<vector<int>> adj(arr.size());
        unordered_map<int, vector<int>> ht;

        for(int i=0; i < arr.size(); i++) {
            ht[arr[i]].push_back(i);
        }

        vector<int> vis(arr.size(), false);

        return solve(0, arr, ht, vis);
    }
};