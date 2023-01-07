/*
Problem Title: 2090 - K Radius Subarray Averages
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/k-radius-subarray-averages
Submission Url: https://leetcode.com/problems/k-radius-subarray-averages/submissions/593701169
*/

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> ans(nums.size(), -1);
        
        if(k >= nums.size()){
            return ans;
        }
        int sum = 0;
        for(int i=0;i<min(2*k, (int)nums.size());i++){
            sum += nums[i];
        }
        for(int i=k; i<nums.size()-k;i++){
            sum += nums[i+k];
            ans[i] = sum/(2*k+1);
            sum -= nums[i-k];
        }
        
        return ans;
    }
};