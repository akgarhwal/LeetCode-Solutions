/*
Problem Title: 974 - Subarray Sums Divisible by K
Lang: C++
Runtime: 49 ms
Memory: 30 MB
Problem Url: https://leetcode.com/problems/subarray-sums-divisible-by-k
Submission Url: https://leetcode.com/problems/subarray-sums-divisible-by-k/submissions/880884661
*/

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> modCount(k, 0);
        int prefixMod = 0;
        modCount[prefixMod] = 1;
        int ans = 0;

        for(int num : nums){
            prefixMod = ((prefixMod + num) % k + k) % k;
            ans += modCount[prefixMod];
            modCount[prefixMod] += 1;
        }

        return ans;
    }
};