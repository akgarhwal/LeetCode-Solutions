/*
Problem Title: 2588 - Count the Number of Beautiful Subarrays
Lang: C++
Runtime: 355 ms
Memory: 120.5 MB
Problem Url: https://leetcode.com/problems/count-the-number-of-beautiful-subarrays
Submission Url: https://leetcode.com/problems/count-the-number-of-beautiful-subarrays/submissions/913839535
*/

class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        long long ans = 0LL;
        unordered_map<int, int> ht;
        int prefix_xor = 0;
        ht[0] = 1;

        for(int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            prefix_xor ^= num;

            if(ht.count(prefix_xor) > 0) {
                ans += ht[prefix_xor];
            }

            ht[prefix_xor] += 1;
        }

        return ans;
    }
};