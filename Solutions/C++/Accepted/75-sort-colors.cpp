/*
Problem Title: 75 - Sort Colors
Lang: C++
Runtime: 8 ms
Memory: 8.6 MB
Problem Url: https://leetcode.com/problems/sort-colors
Submission Url: https://leetcode.com/problems/sort-colors/submissions/352125860
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int last = nums.size()-1, first = 0, cur = 0;
        while(cur <= last){
            
            if(nums[cur] == 0){
                swap(nums[cur], nums[first]);
                first++;
            }
            else if(nums[cur] == 2){
                swap(nums[cur], nums[last]);
                last--;
                cur--;
            }
            cur++;
        }
    }
};