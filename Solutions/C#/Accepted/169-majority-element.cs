/*
Problem Title: 169 - Majority Element
Lang: C#
Runtime: 120 ms
Memory: 29.3 MB
Problem Url: https://leetcode.com/problems/majority-element
Submission Url: https://leetcode.com/problems/majority-element/submissions/301106916
*/

public class Solution {
    public int MajorityElement(int[] nums) {
        int ans = -1, count = 0;
        foreach(int num in nums){
            if(count == 0){
                ans = num;
            }
            if (ans == num){
                count += 1;
            }
            else{
                count -= 1;
            }
        }
        return ans;
    }
}