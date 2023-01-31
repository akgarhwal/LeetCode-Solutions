/*
Problem Title: 69 - Sqrt(x)
Lang: C++
Runtime: 6 ms
Memory: 6 MB
Problem Url: https://leetcode.com/problems/sqrtx
Submission Url: https://leetcode.com/problems/sqrtx/submissions/887784869
*/

class Solution {
public:
    int mySqrt(int x) {
        int ans=0;
        int n = x;
        int lo =0,hi = x;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(mid*1LL*mid <= (long long)n){
                ans = mid;
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
        }
        return ans;
    }
    
};