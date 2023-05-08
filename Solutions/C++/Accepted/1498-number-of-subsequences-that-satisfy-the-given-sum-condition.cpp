/*
Problem Title: 1498 - Number of Subsequences That Satisfy the Given Sum Condition
Lang: C++
Runtime: 140 ms
Memory: 49.8 MB
Problem Url: https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition
Submission Url: https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/submissions/945470579
*/

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        int mod = 1e9+7;

        sort(nums.begin(), nums.end());
        
        vector<int> power(n, 1);
        for (int i = 1; i < n; ++i) {
            power[i] = (power[i - 1] * 2) % mod;
        }
        
        int answer = 0;
        int left = 0, right = n - 1;

        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                answer += power[right - left];
                answer %= mod;
                left++;
            } else {
                right--;
            }
        }
        
        return answer;
    }
};