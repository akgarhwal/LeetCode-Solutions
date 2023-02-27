/*
Problem Title: 2574 - Left and Right Sum Differences
Lang: C++
Runtime: 7 ms
Memory: 11.2 MB
Problem Url: https://leetcode.com/problems/left-and-right-sum-differences
Submission Url: https://leetcode.com/problems/left-and-right-sum-differences/submissions/905003530
*/

class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        vector<int> sum(nums.size(), 0);
        int temp = 0;
        for(int i=nums.size()-1; i >= 0; i--) {
            sum[i] = temp;
            temp += nums[i];
        }
        
        vector<int> ans(nums.size(), 0);
        temp = nums[0];
        ans[0] = sum[0];
        for(int i=1; i < nums.size(); i++) {
            ans[i] = abs(temp - sum[i]);
            temp += nums[i];
        }
        
        return ans;
    }
};