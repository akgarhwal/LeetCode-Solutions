/*
Problem Title: 1626 - Best Team With No Conflicts
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/best-team-with-no-conflicts
Submission Url: https://leetcode.com/problems/best-team-with-no-conflicts/submissions/888453957
*/

class Solution {
public:

    int dfs(int root, vector<bool>& vis, vector<vector<int>>& adj, vector<pair<int,int>>& vi) {
        if(vis[root]){
            return 0;
        }

        vis[root] = true;
        int score = vi[root].second;
        for(int x = 0; x < adj[root].size(); x++) {
            if(!vis[adj[root][x]]) {
                score += dfs(adj[root][x], vis, adj, vi);
            }
        }
        return score;
    }

    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> vi;
        for(int i=0; i < scores.size(); i++) {
            vi.push_back({ages[i], scores[i]});
        }
        sort(vi.begin(), vi.end(), [](pair<int,int> p1, pair<int,int> p2) {
            if(p1.first != p2.first) {
                return p1.first <= p2.first;
            }
            return p1.second <= p2.second;
        });

        vector<vector<int>> adj(scores.size());

        for(int i = 0; i < scores.size(); i++ ) {
            int mxsp = i;
            for(int j = i+1; j < scores.size(); j++) {
                if(vi[j].second >= vi[mxsp].second){
                    adj[i].push_back(j);
                } else if( vi[j].first == vi[mxsp].first and vi[j].second == vi[mxsp].second){
                    adj[i].push_back(j);
                }
                
                if(vi[j].second > vi[mxsp].second) {
                    mxsp = j;
                }
            }
        }

        int maxScore = INT_MIN;
        for(int i = 0; i < adj.size(); i++ ) {
            vector<bool> vis(scores.size(), false);
            maxScore = max(maxScore, dfs(i, vis, adj, vi));
            
        }
        return maxScore;
    }
};