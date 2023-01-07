/*
Problem Title: 35 - Search Insert Position
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/search-insert-position
Submission Url: https://leetcode.com/problems/search-insert-position/submissions/351647912
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int index = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        if(index > 0 and index < nums.size() and nums[index-1] == target){
            index--;
        }
        return index;
    }
};