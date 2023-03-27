/*
Problem Title: 2602 - Minimum Operations to Make All Array Elements Equal
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/minimum-operations-to-make-all-array-elements-equal
Submission Url: https://leetcode.com/problems/minimum-operations-to-make-all-array-elements-equal/submissions/922272829
*/

class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        vector<long long> ans;
        
        for(int i = 0; i < queries.size(); i++) {
            int num = queries[i];
            long long temp = 0LL;
            
            for(int j = 0; j < nums.size(); j++) {
                temp += abs(num - nums[j]);
            }
            
            ans.push_back(temp);
        }
        
        return ans;
    }
};