/*
Problem Title: 153 - Find Minimum in Rotated Sorted Array
Lang: C++
Runtime: 0 ms
Memory: 10.1 MB
Problem Url: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array
Submission Url: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/submissions/893003531
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0, hi = nums.size()-1;

        while(lo < hi) {
            int mid = lo + (hi-lo)/2;
            if(nums[mid] > nums[hi]) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return nums[lo];
    }
};