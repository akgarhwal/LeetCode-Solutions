/*
Problem Title: 1567 - Maximum Length of Subarray With Positive Product
Lang: C++
Runtime: 104 ms
Memory: 57.8 MB
Problem Url: https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product
Submission Url: https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/submissions/498155445
*/

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int framestart = -1, firstneg = -2, len = 0, neg = 0;
        for (int i = 0; i < nums.size(); i++) 
        {
            if (nums[i] == 0) // reset everytime if zero
            {  
                neg = 0;framestart = i;firstneg = -2;
            } 
            else 
            {
                if (nums[i] < 0) neg++;  // number of negatives in  current frame means (frame excluding zero)
                if (neg == 1 && firstneg == -2) firstneg = i;   // init firstneg cnt neg;
                if (neg % 2 == 0) len = max(len, i - framestart);  //if curr cnt neg is framestart;
                else len = max(len, i - firstneg);  // first firstneg after last zero;
            }
        }
        return len;
    }
};