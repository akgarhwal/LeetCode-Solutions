/*
Problem Title: 2560 - House Robber IV
Lang: C++
Runtime: 178 ms
Memory: 57 MB
Problem Url: https://leetcode.com/problems/house-robber-iv
Submission Url: https://leetcode.com/problems/house-robber-iv/submissions/891769911
*/

class Solution {
public:
    


    
    
    int minCapability(vector<int>& nums, int k) {
        int ans = INT_MAX;
        int lo = 1, hi = 1000000000;
        while( lo <= hi) {
            int mid = lo + (hi-lo)/2;

            int count = 0;
            for(int i=0;i<nums.size();i++) {
                if(nums[i] <= mid){
                    count++;
                    i++;
                }
            }

            if(count >= k) {
                ans = min(ans, mid);
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};