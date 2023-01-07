/*
Problem Title: 684 - Redundant Connection
Lang: C++
Runtime: 8 ms
Memory: 9.1 MB
Problem Url: https://leetcode.com/problems/redundant-connection
Submission Url: https://leetcode.com/problems/redundant-connection/submissions/513288139
*/

class Solution {
public:
    int findPar(vector<int> &par, int x){
        if(par[x] != x){
            return par[x] = findPar(par, par[x]);
        }
        return par[x];
    }
    void merge(int x, int y, vector<int> &par){
        int px = findPar(par, x);
        int py = findPar(par, y);
        if(px != py){
            par[px] = py;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int N = edges.size();
        vector<int> ans;
        vector<int> par(N+1, 0);
        for(int i=1;i<=N;i++){
            par[i] = i;
        }
        for(auto edge : edges){
            if( findPar(par, edge[0]) == findPar(par, edge[1]) ){
                ans = edge;
                break;
            }
            merge(edge[0], edge[1], par);
        }
        return ans;
    }
};