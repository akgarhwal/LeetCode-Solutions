/*
Problem Title: 2602 - Minimum Operations to Make All Array Elements Equal
Lang: C++
Runtime: 280 ms
Memory: 81.1 MB
Problem Url: https://leetcode.com/problems/minimum-operations-to-make-all-array-elements-equal
Submission Url: https://leetcode.com/problems/minimum-operations-to-make-all-array-elements-equal/submissions/922361507
*/

class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());

        vector<long long int> rsum(nums.size());
        rsum[0] = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            rsum[i] = ((long long)nums[i]) + rsum[i-1];
        }

        vector<long long> ans;
        
        for(int i = 0; i < queries.size(); i++) {
            int num = queries[i];
            long long temp = 0LL;
            
            int index = lower_bound(nums.begin(), nums.end(), num)  -  nums.begin();

            // calc left
            if(index > 0) {
                temp += (index * 1LL *  num) - rsum[index-1];
            }

            // calc right
            if(index < nums.size()) {
                long long rightSum = rsum[nums.size()-1] - (index == 0 ? 0 : rsum[index-1]);
                int rightNumCount = nums.size() - index;

                temp += (rightSum - (rightNumCount * 1LL *  num));
            }

            ans.push_back(temp);
        }
        
        return ans;
    }
};