/*
Problem Title: 287 - Find the Duplicate Number
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/find-the-duplicate-number
Submission Url: https://leetcode.com/problems/find-the-duplicate-number/submissions/504314832
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int first = nums[0], second = nums[first];
        while(first != second){
            first = nums[first];
            second = nums[nums[second]];
            cout<<first<<" - " <<second<<endl;
        }
        return nums[first];
    }
};