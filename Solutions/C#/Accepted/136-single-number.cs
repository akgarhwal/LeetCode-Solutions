/*
Problem Title: 136 - Single Number
Lang: C#
Runtime: 92 ms
Memory: 26.4 MB
Problem Url: https://leetcode.com/problems/single-number
Submission Url: https://leetcode.com/problems/single-number/submissions/318162715
*/

public class Solution {
    public int SingleNumber(int[] nums) {
        int result = 0;
        
        foreach(int num in nums){
            result = result ^ num;
        }
        
        return result;
    }
}