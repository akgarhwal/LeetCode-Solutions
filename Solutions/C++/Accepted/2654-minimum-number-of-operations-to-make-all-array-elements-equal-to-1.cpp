/*
Problem Title: 2654 - Minimum Number of Operations to Make All Array Elements Equal to 1
Lang: C++
Runtime: 0 ms
Memory: 27.6 MB
Problem Url: https://leetcode.com/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1
Submission Url: https://leetcode.com/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1/submissions/938309394
*/

class Solution {
public:
    int minOperations(vector<int>& nums) {

        int ones = count(nums.begin(), nums.end(), 1);

        if(ones) {
            return nums.size() - ones;
        }

        int minOps = INT_MAX;
        for(int i = 0; i < nums.size() - 1; i++) {
            int gcd = nums[i];
            for(int j = i + 1; j < nums.size(); j++) {

                gcd = __gcd(gcd, nums[j]);

                if(gcd == 1){
                    minOps = min(minOps, (j - i) + int(nums.size()-1));
                }
            }
        }

        return minOps == INT_MAX ? -1 : minOps;
    }
};