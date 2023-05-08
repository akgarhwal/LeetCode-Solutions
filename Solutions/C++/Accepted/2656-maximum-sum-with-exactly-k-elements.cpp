/*
Problem Title: 2656 - Maximum Sum With Exactly K Elements 
Lang: C++
Runtime: 56 ms
Memory: 70.7 MB
Problem Url: https://leetcode.com/problems/maximum-sum-with-exactly-k-elements
Submission Url: https://leetcode.com/problems/maximum-sum-with-exactly-k-elements/submissions/942949384
*/

class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int mx = INT_MIN;
        
        for(int x : nums) {
            mx = max(mx, x);
        }
        
        int ans = 0;
        while(k--) {
            ans += mx;
            mx++;
        }
        
        return ans;
    }
};