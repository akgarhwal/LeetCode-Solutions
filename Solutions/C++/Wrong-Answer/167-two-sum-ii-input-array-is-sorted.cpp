/*
Problem Title: 167 - Two Sum II - Input Array Is Sorted
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted
Submission Url: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/submissions/889738563
*/

class Solution {
public:

    int findX(vector<int>& nums, int x) {
        int lo = 0, hi = nums.size()-1;
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid] < x) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        if(lo >= 0 and nums[lo] == x){
            return lo;
        }
        return -1;
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++) {
            int index = findX(nums, target - nums[i]);
            if(index > i) {
                ans.push_back(i+1);
                ans.push_back(index+1);
                break;
            }
        }

        return ans;
    }
};