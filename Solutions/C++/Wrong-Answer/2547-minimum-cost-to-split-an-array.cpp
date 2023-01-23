/*
Problem Title: 2547 - Minimum Cost to Split an Array
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/minimum-cost-to-split-an-array
Submission Url: https://leetcode.com/problems/minimum-cost-to-split-an-array/submissions/882840171
*/

class Solution {
public:
    
//     int solve(int st, int end, vector<int>& nums, vector<vector<int>>& dp, int k) {
//         if(st > end) {
//             return 1e9+1;
//         }
//         if(dp[st][end] != (1e9+1)){
//             return dp[st][end];
//         }
//         if(st == end){
//             dp[st][end] = k;
//             return k;
//         }
        
//         unordered_map<int,int> freq;
//         for(int x = st; x <= end; x++){
//             freq[nums[x]]++;
//         }
//         int count = 0;
//         for(auto ele : freq) {
//             if(ele.second > 1) {
//                 count+=ele.second;
//             }
//         }
//         int minCost = k + count;
//         for(int i = st; i < end; i++) {
//             minCost = min(minCost, solve(st, i, nums, dp, k) + solve(i+1, end, nums, dp, k) );
//         }
        
//         return dp[st][end] = minCost;
//     }
    
    int minCost(vector<int>& nums, int k) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 1e9+1));
        
        unordered_map<int, int> freq;
        
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
            dp[i][i] = k + (freq[nums[i]] > 1);
        }

        
        for (int len = 1; len <= nums.size(); len++) {
            
            freq.clear();
            for (int k = 0; k <= len-1; k++) {
                freq[nums[k]]++;
            }
            
            
            for (int i = 0; i <= (int(nums.size())) - len; i++) {
                int j = i + len - 1;
                
                if(i > 0){
                    freq[nums[i]]--;
                    freq[nums[i+len-1]]++;
                }
                
                
                int count = 0;
                for (auto ele : freq) {
                    if (ele.second > 1) {
                        count += ele.second;
                    }
                }
                int minCost = k + count;
                for (int k = i; k < j; k++) {
                    minCost = min(minCost, dp[i][k] + dp[k + 1][j]);
                }
                dp[i][j] = minCost;
            }
        }
        
        return dp[0][nums.size()-1];
    }
};