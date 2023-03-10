/*
Problem Title: 137 - Single Number II
Lang: C++
Runtime: 8 ms
Memory: 8.8 MB
Problem Url: https://leetcode.com/problems/single-number-ii
Submission Url: https://leetcode.com/problems/single-number-ii/submissions/313024059
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0, two = 0;
    
        for(auto x: nums){

            one = (one^x) & (~two);

            two = (two^x) & (~one);

        }
        return one;
    }
};