/*
Problem Title: 2202 - Maximize the Topmost Element After K Moves
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/maximize-the-topmost-element-after-k-moves
Submission Url: https://leetcode.com/problems/maximize-the-topmost-element-after-k-moves/submissions/883752139
*/

class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        
        int ans = -1;
        for(int i = 0; i < min(k+1, (int)nums.size()); i++) {
            if( i != k-1){
                ans = max(ans, nums[i]);
            }
        }
        return ans;
    }
};