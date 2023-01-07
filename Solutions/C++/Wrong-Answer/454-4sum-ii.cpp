/*
Problem Title: 454 - 4Sum II
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/4sum-ii
Submission Url: https://leetcode.com/problems/4sum-ii/submissions/324219254
*/

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> mp1, mp2;
        
        for(int a : A){
            for(int b : B){
                mp1[a+b] += 1;
            }
        }
        for(int c : C){
            for(int d : D){
                mp2[c+d] += 1;
            }
        }
        
        int ans = 0;
        for(auto pi : mp1){
            
            if(mp2.count(-pi.first) > 0){
                ans += mp2[-pi.first];
            }
            
        }
        
        return ans;
    }
};