/*
Problem Title: 367 - Valid Perfect Square
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/valid-perfect-square
Submission Url: https://leetcode.com/problems/valid-perfect-square/submissions/336617810
*/

class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num < 1) return false;
        int lo = 1, hi = num;
        
        
        while( lo <= hi){
            
            int mid = lo + (hi-lo) / 2;
            
            if(mid*mid == num){
                return true;
            }
            if (mid*mid < num){
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
            
        }
        
        return false;
    }
};