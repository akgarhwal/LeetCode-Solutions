/*
Problem Title: 287 - Find the Duplicate Number
Lang: C#
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/find-the-duplicate-number
Submission Url: https://leetcode.com/problems/find-the-duplicate-number/submissions/303446528
*/

public class Solution {
    public int FindDuplicate(int[] nums) {
        int res = 0;
        for(int i=0; i < nums.Length; i++){
            if(i != (nums.Length - 1))
                res = res ^ nums[i] ^ (i+1);
            else
                res = res ^ nums[i];
        }
        return res;
    }
}