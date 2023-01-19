/*
Problem Title: 1470 - Shuffle the Array
Lang: C++
Runtime: 5 ms
Memory: 9.6 MB
Problem Url: https://leetcode.com/problems/shuffle-the-array
Submission Url: https://leetcode.com/problems/shuffle-the-array/submissions/880234398
*/

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(2*n, 0);
        int x = 0, y = n;
        for(int i = 0; i < nums.size(); i++) {
            if( (i%2) == 0 ) {
                ans[i] = nums[x++];
            } else {
                ans[i] = nums[y++];
            }
        }
        return ans;
    }
};