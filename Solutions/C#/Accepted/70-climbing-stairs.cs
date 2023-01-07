/*
Problem Title: 70 - Climbing Stairs
Lang: C#
Runtime: 36 ms
Memory: 14.6 MB
Problem Url: https://leetcode.com/problems/climbing-stairs
Submission Url: https://leetcode.com/problems/climbing-stairs/submissions/302035652
*/

public class Solution {
    public int ClimbStairs(int n) {
        int res = 1, last = 1, second_last = 1;
        for(int step = 2; step <= n; step ++){
            res = last + second_last;
            second_last = last;
            last = res;
        }
        return res;
    }
}