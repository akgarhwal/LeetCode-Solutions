/*
Problem Title: 633 - Sum of Square Numbers
Lang: C++
Runtime: 48 ms
Memory: 5.8 MB
Problem Url: https://leetcode.com/problems/sum-of-square-numbers
Submission Url: https://leetcode.com/problems/sum-of-square-numbers/submissions/543927542
*/

class Solution {
public:
    int sqrtBS(int num){
        int lo = 0, hi = num;
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            long midsq = mid*1LL*mid;
            if(midsq == (long)num){
                return mid;
            }
            if( midsq < (long)num){
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
            // cout<<mid<<" - "<<midsq<<endl;
            
        }
        return lo;
    }
    bool judgeSquareSum(int c) {
        int limit = sqrtBS(c);
        
        for(int i = 0; i <= limit; i++){
            
            long sj = c - (i*1LL*i);
            if(sj < 0 ) continue;
            int j = sqrtBS(sj);
            
            if( j*1LL*j == sj){
                return true;
            }
        }
        return false;
    }
};