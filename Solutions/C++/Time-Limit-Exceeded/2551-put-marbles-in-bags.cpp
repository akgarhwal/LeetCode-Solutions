/*
Problem Title: 2551 - Put Marbles in Bags
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/put-marbles-in-bags
Submission Url: https://leetcode.com/problems/put-marbles-in-bags/submissions/887208946
*/

class Solution {
    int mi = INT_MAX;
    int mx = INT_MIN;
public:
    
    void solve(int start, int cur, int k, vector<int>& weights, vector<pair<int,int>>& dist) {
        if(cur > weights.size() or k < 0) {
            return;
        }
        if(k == 0) {
            int score = 0;
            dist[dist.size()-1].second = weights.size()-1;
            for(auto pi : dist) {
                score += (weights[pi.first] + weights[pi.second]);
            }
            mi = min(mi, score);
            mx = max(mx, score);
            return;
        }
        for(int i=cur; i < weights.size(); i++){
            
            dist.push_back({start, i});
            solve(i+1, i+1, k-1, weights, dist);
            
            dist.pop_back();
            solve(start, i+1, k, weights, dist);
        }
        
                
    }
    
    
    long long putMarbles(vector<int>& weights, int k) {
        vector<pair<int,int>> dist;
        solve(0, 0, k, weights, dist);
        return mx-mi;
    }
};