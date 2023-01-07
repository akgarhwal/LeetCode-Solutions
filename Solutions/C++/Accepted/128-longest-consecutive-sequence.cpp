/*
Problem Title: 128 - Longest Consecutive Sequence
Lang: C++
Runtime: 196 ms
Memory: 39.6 MB
Problem Url: https://leetcode.com/problems/longest-consecutive-sequence
Submission Url: https://leetcode.com/problems/longest-consecutive-sequence/submissions/503812012
*/

class Solution {
public:
    
    int findPar(int x, unordered_map<int,int> &par){
        if(par[x] == x){
            return x;
        }
        return par[x] = findPar(par[x], par);
    }
    
    void merge(unordered_map<int,int> &par, unordered_map<int,int> &size, int x, int y){
        int px = findPar(x, par);
        int py = findPar(y, par);
        
        if(px != py){
            if(size[px] > size[py]){
                par[py] = px;
                size[px] += size[py];
            }
            else{
                par[px] = py;
                size[py] += size[px];          
            }
        }
    }
    
    int longestConsecutive(vector<int>& nums) {
        
        unordered_map<int,int> par, size;
        
        for(int x : nums){
            if(par.find(x) == par.end()){
                par[x] = x;
                size[x] = 1;
            }
            if(par.find(x-1) != par.end()){
                merge(par, size, x, x-1);
            }
            if(par.find(x+1) != par.end()) {
                merge(par, size, x, x+1);
            }
        }
        
        int ans = 0;
        for(auto ele : size){
            ans = max(ans, ele.second);
        }
        return ans;
    }
};