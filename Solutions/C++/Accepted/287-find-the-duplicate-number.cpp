/*
Problem Title: 287 - Find the Duplicate Number
Lang: C++
Runtime: 232 ms
Memory: 61.3 MB
Problem Url: https://leetcode.com/problems/find-the-duplicate-number
Submission Url: https://leetcode.com/problems/find-the-duplicate-number/submissions/504315863
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int first = nums[0], second = nums[first];
        while(first != second){
            first = nums[first];
            second = nums[nums[second]];
        }
        first = 0;
        while(first != second){
            first = nums[first];
            second = nums[second];
        }
        return first;
    }
};