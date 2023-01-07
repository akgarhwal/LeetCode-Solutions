/*
Problem Title: 704 - Binary Search
Lang: C++
Runtime: 75 ms
Memory: 27.6 MB
Problem Url: https://leetcode.com/problems/binary-search
Submission Url: https://leetcode.com/problems/binary-search/submissions/768104013
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size();
        while(low < high){
            
            int mid = (low+high)>>1;
            
            if(nums[mid] == target){
                return mid;
            }
            if(nums[mid] < target){
                low = mid+1;
            }
            else{
                high = mid;
            }
        }
        return -1;
    }
};