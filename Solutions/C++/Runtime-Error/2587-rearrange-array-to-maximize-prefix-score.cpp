/*
Problem Title: 2587 - Rearrange Array to Maximize Prefix Score
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/rearrange-array-to-maximize-prefix-score
Submission Url: https://leetcode.com/problems/rearrange-array-to-maximize-prefix-score/submissions/913608084
*/

class Solution {
public:
    int maxScore(vector<int>& nums) {
        int ans = 0, sum = 0;
        sort(nums.begin(), nums.end());
        for(int i = nums.size()-1; i>= 0 ; i--) {
            sum += nums[i];
            if(sum > 0) {
                ans += 1;
            }
        }
        return ans;
    }
};