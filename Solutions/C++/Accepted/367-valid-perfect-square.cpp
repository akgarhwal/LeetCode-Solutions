/*
Problem Title: 367 - Valid Perfect Square
Lang: C++
Runtime: 0 ms
Memory: 5.9 MB
Problem Url: https://leetcode.com/problems/valid-perfect-square
Submission Url: https://leetcode.com/problems/valid-perfect-square/submissions/336618159
*/

class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num < 1) return false;
        int lo = 1, hi = num;
        
        
        while( lo <= hi){
            
            int mid = lo + (hi-lo) / 2;
            
            if(mid*1LL*mid == (long long)num){
                return true;
            }
            if (mid*1LL*mid < (long long)num){
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
            
        }
        
        return false;
    }
};