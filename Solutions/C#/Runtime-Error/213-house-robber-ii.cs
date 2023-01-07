/*
Problem Title: 213 - House Robber II
Lang: C#
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/house-robber-ii
Submission Url: https://leetcode.com/problems/house-robber-ii/submissions/302974148
*/

public class Solution {
    
    private int RobHelper(int[] nums, int st, int end){
        int[] res = new int[end-st+1];
        for(int index = st; index < end; index++){
            if(index == st){
                res[index] = nums[index];
            }
            else if (index == st+1){
                res[index] = Math.Max(nums[index-1], nums[index]);
            }
            else{
                res[index] = Math.Max(res[index-1], res[index-2] + nums[index]);
            }
        }
        return end-st+1 == 0 ? 0 : res[end-st-1];
    }
    
    public int Rob(int[] nums) {
        int length = nums.Length;
        int res = RobHelper(nums, 0, length-1);
        res = Math.Max(res, RobHelper(nums, 1, length));
        
       
        return length == 0 ? 0 : res;
    }
}