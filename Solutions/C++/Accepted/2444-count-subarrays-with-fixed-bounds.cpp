/*
Problem Title: 2444 - Count Subarrays With Fixed Bounds
Lang: C++
Runtime: 122 ms
Memory: 70.3 MB
Problem Url: https://leetcode.com/problems/count-subarrays-with-fixed-bounds
Submission Url: https://leetcode.com/problems/count-subarrays-with-fixed-bounds/submissions/908839113
*/

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int left = -1, minPos = -1, maxPos = -1;

        for(int i = 0; i < nums.size(); i++) {

            if(nums[i] < minK or nums[i] > maxK) {
                left = i;
            }
            if(nums[i] == minK) {
                minPos = i;
            }
            if(nums[i] == maxK) {
                maxPos = i;
            }

            ans += max(0, (min(minPos, maxPos) - left));
        }

        return ans;
    }
};