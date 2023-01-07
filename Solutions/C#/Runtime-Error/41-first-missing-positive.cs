/*
Problem Title: 41 - First Missing Positive
Lang: C#
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/first-missing-positive
Submission Url: https://leetcode.com/problems/first-missing-positive/submissions/303447892
*/

public class Solution {
    public int FirstMissingPositive(int[] nums) {
        int lastIndex = 0;
        for(int ind = 0; ind < nums.Length; ind++){
            
            if(nums[ind] > 0 && nums[ind] < nums.Length && nums[ind] != ind+1) {
                int temp = nums[ind];
                nums[ind] = nums[nums[ind]];
                nums[nums[ind]] = temp;
            }
            while(lastIndex+1 == nums[lastIndex]){
                lastIndex += 1;
            }
            
        }
        return lastIndex+1;
    }
}