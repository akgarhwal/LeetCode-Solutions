/*
Problem Title: 581 - Shortest Unsorted Continuous Subarray
Lang: C++
Runtime: 40 ms
Memory: 26.6 MB
Problem Url: https://leetcode.com/problems/shortest-unsorted-continuous-subarray
Submission Url: https://leetcode.com/problems/shortest-unsorted-continuous-subarray/submissions/504776688
*/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        int small = INT_MAX, large = INT_MIN;
        
        for(int i=1; i < nums.size(); i++){
            if(nums[i-1] > nums[i]){
                small = min(small, nums[i]);
                large = max(large, nums[i-1]);
            }
        }
        
        int st = -1, end = -1;
        for(int i = 0;  i < nums.size(); i++){
            if(nums[i] > small){
                st = i;
                break;
            }
        }
        for(int i = nums.size()-1;  i >= 0 ; i--){
            if(nums[i] < large){
                end = i;
                break;
            }
        }
        return end == -1 ? 0 : end-st + 1;
    }
};