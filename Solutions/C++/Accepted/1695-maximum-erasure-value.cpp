/*
Problem Title: 1695 - Maximum Erasure Value
Lang: C++
Runtime: 568 ms
Memory: 156.6 MB
Problem Url: https://leetcode.com/problems/maximum-erasure-value
Submission Url: https://leetcode.com/problems/maximum-erasure-value/submissions/499381698
*/

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int first = 0, second = 0;
        int ans = 0, sum = 0;
        set<int> st;
        while(first < nums.size()) {
            
            while(second < nums.size() and st.find(nums[second]) == st.end()){
                sum += nums[second];
                st.insert(nums[second++]);
            }
            
            ans = max(ans, sum);
            sum -= nums[first];
            st.erase(nums[first++]);
        }
        return ans;
    }
};