/*
Problem Title: 724 - Find Pivot Index
Lang: C++
Runtime: 23 ms
Memory: 31.1 MB
Problem Url: https://leetcode.com/problems/find-pivot-index
Submission Url: https://leetcode.com/problems/find-pivot-index/submissions/763095177
*/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int pivotIndex = -1;
        int lsum = 0, rsum = 0;
        for(int num : nums){
            rsum += num;
        }
        for(int index = 0; index< nums.size(); index++){
            rsum -= nums[index];
            if(lsum == rsum){
                return index;
            }
            lsum += nums[index];
        }
        return pivotIndex;
    }
};