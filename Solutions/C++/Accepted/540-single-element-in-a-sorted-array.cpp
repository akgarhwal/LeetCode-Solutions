/*
Problem Title: 540 - Single Element in a Sorted Array
Lang: C++
Runtime: 16 ms
Memory: 11 MB
Problem Url: https://leetcode.com/problems/single-element-in-a-sorted-array
Submission Url: https://leetcode.com/problems/single-element-in-a-sorted-array/submissions/338609144
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, hi = nums.size()-1;
        while(low < hi){
            int mid = low + (hi-low)/2;
            if(mid % 2 == 0 and nums[mid] == nums[mid+1]){
                low = mid + 1;
            }
            else if (mid%2 == 1 and nums[mid] == nums[mid-1]){
                low = mid + 1;
            }
            else{
                hi = mid;
            }
        }
        return nums[low];
    }
};