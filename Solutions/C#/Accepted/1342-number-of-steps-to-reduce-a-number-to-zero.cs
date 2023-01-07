/*
Problem Title: 1342 - Number of Steps to Reduce a Number to Zero
Lang: C#
Runtime: 40 ms
Memory: 14.6 MB
Problem Url: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero
Submission Url: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/submissions/302327024
*/

public class Solution {
    public int NumberOfSteps (int num) {
        int ans = -1;
        while (num > 0) {
            ans += (num&1) == 0 ? 1 : 2;
            num = num >> 1;
        }
        return ans;
    }
}