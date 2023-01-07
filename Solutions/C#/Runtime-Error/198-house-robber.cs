/*
Problem Title: 198 - House Robber
Lang: C#
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/house-robber
Submission Url: https://leetcode.com/problems/house-robber/submissions/302027958
*/

public class Solution {
    public int Rob(int[] nums) {
        int length = nums.Length;
        int[,] res = new int[2, length];
        
        for(int index = 0; index < length; index++){
            if(index == 0){
                res[0,index] = 0;
                res[1,index] = nums[index];                
            }
            else{
                res[0,index] = Math.Max(res[0,index-1], res[1,index-1]);
                res[1,index] = res[0,index-1] + nums[index];
            }
        }
        return Math.Max(res[0, length-1], res[1, length-1]);
    }
}