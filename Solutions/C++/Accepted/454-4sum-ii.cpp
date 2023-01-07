/*
Problem Title: 454 - 4Sum II
Lang: C++
Runtime: 364 ms
Memory: 38.7 MB
Problem Url: https://leetcode.com/problems/4sum-ii
Submission Url: https://leetcode.com/problems/4sum-ii/submissions/324221408
*/

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> mp1;
        int ans = 0;

        for(int a : A){
            for(int b : B){
                mp1[a+b]++;
            }
        }
        for(int c : C){
            for(int d : D){                
                ans += mp1[-(c+d)];
            }
        }
        
        return ans;
    }
};