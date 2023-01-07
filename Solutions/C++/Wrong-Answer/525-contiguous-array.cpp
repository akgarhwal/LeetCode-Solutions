/*
Problem Title: 525 - Contiguous Array
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/contiguous-array
Submission Url: https://leetcode.com/problems/contiguous-array/submissions/324069505
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ans = 0, temp = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != nums[i-1]){
                temp++;
            }
            else{
                ans = max(ans, temp);
                temp = 1;
            }
        }
        ans = max(ans, temp);
        return ans%2 ? ans-1 : ans;
    }
};