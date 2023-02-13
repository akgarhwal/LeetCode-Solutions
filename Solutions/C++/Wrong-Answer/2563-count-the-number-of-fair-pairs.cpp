/*
Problem Title: 2563 - Count the Number of Fair Pairs
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/count-the-number-of-fair-pairs
Submission Url: https://leetcode.com/problems/count-the-number-of-fair-pairs/submissions/896254680
*/

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        
        long long ans = 0;
        
        for(int i= 0; i < nums.size(); i++) {
            
            int x = lower - nums[i];
            
            int y = upper - nums[i];
            
            int lb = lower_bound(nums.begin(), nums.end(), x) - nums.begin();
            
            int ub = upper_bound(nums.begin(), nums.end(), y) - nums.begin();
            
            ans += (ub - lb);
        }
        
        int n = nums.size();
        long long mx = (n * (n-1))/2;
        
        return min(mx, ans>>1);
    }
};