/*
Problem Title: 2587 - Rearrange Array to Maximize Prefix Score
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/rearrange-array-to-maximize-prefix-score
Submission Url: https://leetcode.com/problems/rearrange-array-to-maximize-prefix-score/submissions/913606756
*/

class Solution {
public:
    int maxScore(vector<int>& nums) {
        int ans = 0;
        for(int num : nums) {
            if(num > 0) {
                ans += num;
            }
        }
        return ans;
    }
};