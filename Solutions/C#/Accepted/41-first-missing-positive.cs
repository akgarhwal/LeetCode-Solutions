/*
Problem Title: 41 - First Missing Positive
Lang: C#
Runtime: 84 ms
Memory: 24.5 MB
Problem Url: https://leetcode.com/problems/first-missing-positive
Submission Url: https://leetcode.com/problems/first-missing-positive/submissions/303452608
*/

public class Solution {
    public int FirstMissingPositive(int[] nums) {
        int lastIndex = 0;
        for(int ind = 0; ind < nums.Length; ind++){
            
            while(nums[ind] > 0 && nums[ind] < nums.Length && nums[ind] != ind+1) {
                int temp = nums[ind];
                int ind2 = nums[ind] - 1;
                nums[ind] = nums[ind2];
                nums[ind2] = temp;
                if(temp == nums[ind]){
                    break;
                }
            }
            while(lastIndex < nums.Length && (lastIndex+1) == nums[lastIndex]){
                lastIndex += 1;
            }
        }
        return lastIndex+1;
    }
}