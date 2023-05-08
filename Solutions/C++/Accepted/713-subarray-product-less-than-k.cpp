/*
Problem Title: 713 - Subarray Product Less Than K
Lang: C++
Runtime: 106 ms
Memory: 61.3 MB
Problem Url: https://leetcode.com/problems/subarray-product-less-than-k
Submission Url: https://leetcode.com/problems/subarray-product-less-than-k/submissions/945801297
*/

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) {
            return 0;
        }
        
        int prod = 1, ans = 0, left = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            prod *= nums[right];

            while (prod >= k) {
                prod /= nums[left++];
            }

            ans += right - left + 1;
        }

        return ans;
    }
};