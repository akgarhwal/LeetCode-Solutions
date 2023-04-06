/*
Problem Title: 2439 - Minimize Maximum of Array
Lang: C++
Runtime: 130 ms
Memory: 71.4 MB
Problem Url: https://leetcode.com/problems/minimize-maximum-of-array
Submission Url: https://leetcode.com/problems/minimize-maximum-of-array/submissions/928479946
*/

class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int ans = 0;
        long long sum = 0LL;

        for(int i = 0 ; i < nums.size(); i++) {
            sum += nums[i];
            ans = max(ans, (int)( (sum+i) / (i+1) ));
        }

        return ans;
    }
};