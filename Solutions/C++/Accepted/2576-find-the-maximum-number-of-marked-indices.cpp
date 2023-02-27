/*
Problem Title: 2576 - Find the Maximum Number of Marked Indices
Lang: C++
Runtime: 176 ms
Memory: 60 MB
Problem Url: https://leetcode.com/problems/find-the-maximum-number-of-marked-indices
Submission Url: https://leetcode.com/problems/find-the-maximum-number-of-marked-indices/submissions/905092885
*/

class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        int first = 0, second = (nums.size()+1)>>1, ans = 0;
        
        sort(nums.begin(), nums.end());
        
        while(second < (int)nums.size()) {
            if(nums[first]*2 <= nums[second]){
                ans += 2;
                first++;
            }
            
            second++;
        }
        
        return ans;
    }
};