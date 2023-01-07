/*
Problem Title: 1383 - Maximum Performance of a Team
Lang: C++
Runtime: 104 ms
Memory: 36.8 MB
Problem Url: https://leetcode.com/problems/maximum-performance-of-a-team
Submission Url: https://leetcode.com/problems/maximum-performance-of-a-team/submissions/503398038
*/

class Solution {
public:
    bool static sortByEff(pair<int,int> a, pair<int,int> b){
        if(a.first == b.first){
            return a.second > b.second;
        }
        return a.first > b.first;
    }
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> eng;
        
        for(int i=0;i<speed.size();i++){
            eng.push_back({efficiency[i], speed[i]});
        }
        sort(eng.begin(), eng.end(), sortByEff);
        
        priority_queue<int, vector<int>, greater<int>> pq;
        long ss = 0, ans = 0;
        for(pair<int,int> cur_eng : eng){
            
            if(pq.size() > k-1){
                ss -= pq.top();
                pq.pop();
            }
            pq.push(cur_eng.second);
            ss += cur_eng.second;            
            ans = max(ans, ss * cur_eng.first);
        }
        return ans % 1000000007;        
    }
};