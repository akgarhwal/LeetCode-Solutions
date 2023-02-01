/*
Problem Title: 34 - Find First and Last Position of Element in Sorted Array
Lang: C++
Runtime: 7 ms
Memory: 13.7 MB
Problem Url: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array
Submission Url: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/submissions/888430086
*/

class Solution {
public:
    int findFirstPosition(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        int ans = -1;
        while(low <= high) {
            int mid = low + (high-low)/2;
            if(nums[mid] == target) {
                ans = mid;
            }
            if(nums[mid] >= target) {
                high = mid-1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
    int findLastPosition(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        int ans = -1;
        while(low <= high) {
            int mid = low + (high-low)/2;
            if(nums[mid] == target) {
                ans = mid;
            }
            if(nums[mid] > target) {
                high = mid-1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        ans.push_back(findFirstPosition(nums, target));
        ans.push_back(findLastPosition(nums, target));
        return ans;
    }
};