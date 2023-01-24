/*
Problem Title: 2202 - Maximize the Topmost Element After K Moves
Lang: C++
Runtime: 164 ms
Memory: 63.6 MB
Problem Url: https://leetcode.com/problems/maximize-the-topmost-element-after-k-moves
Submission Url: https://leetcode.com/problems/maximize-the-topmost-element-after-k-moves/submissions/883753512
*/

class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        if(nums.size() == 1 and k%2 == 1){
            return -1;
        }

        int ans = -1;
        for(int i = 0; i < min(k+1, (int)nums.size()); i++) {
            if( i != k-1){
                ans = max(ans, nums[i]);
            }
        }
        return ans;
    }
};