/*
Problem Title: 283 - Move Zeroes
Lang: C#
Runtime: 244 ms
Memory: 31.8 MB
Problem Url: https://leetcode.com/problems/move-zeroes
Submission Url: https://leetcode.com/problems/move-zeroes/submissions/319479769
*/

public class Solution {
    public void MoveZeroes(int[] nums) {
        int nonZeroCounter = 0;
        for(int index = 0; index < nums.Length; index++){
            if(nums[index] != 0){
                Swap(ref nums[nonZeroCounter++], ref nums[index]);
            }
        }
    }
    private void Swap(ref int first, ref int second){
        int temp = first;
        first = second;
        second = temp;
    }
}
