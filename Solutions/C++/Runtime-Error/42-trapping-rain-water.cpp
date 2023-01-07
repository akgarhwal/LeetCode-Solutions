/*
Problem Title: 42 - Trapping Rain Water
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/trapping-rain-water
Submission Url: https://leetcode.com/problems/trapping-rain-water/submissions/504346842
*/

class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> r_max(height.size(), -1);
        r_max[height.size()-1] = height[height.size()-1];
        for(int i = height.size()-2; i >= 0; i--){
            r_max[i] = max(r_max[i+1], height[i]);
        }
        
        int l_max = -1;
        int ans = 0;
        for(int i = 0;i < height.size(); i++){
            l_max = max(l_max, height[i]);
            int temp_ans = min(l_max, r_max[i]) - height[i];
            ans += temp_ans > 0 ? temp_ans:  0;
        }
        return ans;
    }
};