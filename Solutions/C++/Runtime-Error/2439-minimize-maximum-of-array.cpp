/*
Problem Title: 2439 - Minimize Maximum of Array
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/minimize-maximum-of-array
Submission Url: https://leetcode.com/problems/minimize-maximum-of-array/submissions/928479661
*/

class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int ans = 0;
        int sum = 0;

        for(int i = 0 ; i < nums.size(); i++) {
            sum += nums[i];
            ans = max(ans, ( (sum+i) / (i+1) ));
        }

        return ans;
    }
};