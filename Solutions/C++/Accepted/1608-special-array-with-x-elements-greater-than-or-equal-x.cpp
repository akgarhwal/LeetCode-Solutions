/*
Problem Title: 1608 - Special Array With X Elements Greater Than or Equal X
Lang: C++
Runtime: 3 ms
Memory: 8.4 MB
Problem Url: https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x
Submission Url: https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/submissions/889734693
*/

class Solution {
public:
    
    bool isSpecialBinary(vector<int>& nums, int x){
        int mx = 0;
        int lo = 0, hi = nums.size()-1;
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid] >= x){
                hi = mid - 1;
            } else{
                lo = mid + 1;
            }
        }
        return (nums.size() - lo) == x;
    }

    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        for(int i=0;i<=1000;i++){
            if(isSpecialBinary(nums, i)) {
                return i;
            }
        }
        return -1;
    }
};