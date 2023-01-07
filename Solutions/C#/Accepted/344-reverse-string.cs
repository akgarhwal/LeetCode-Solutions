/*
Problem Title: 344 - Reverse String
Lang: C#
Runtime: 380 ms
Memory: 34.3 MB
Problem Url: https://leetcode.com/problems/reverse-string
Submission Url: https://leetcode.com/problems/reverse-string/submissions/348850649
*/

public class Solution {
    public void ReverseString(char[] s) {
        int length = s.Length;
        for(int index = 0; index < length/2; index++ ) {
            char temp = s[index];
            s[index] = s[length-index - 1];
            s[length-index - 1] = temp;
        }
    }
}