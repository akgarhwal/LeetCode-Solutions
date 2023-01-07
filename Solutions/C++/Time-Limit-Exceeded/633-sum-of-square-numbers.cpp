/*
Problem Title: 633 - Sum of Square Numbers
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/sum-of-square-numbers
Submission Url: https://leetcode.com/problems/sum-of-square-numbers/submissions/543924525
*/

class Solution {
public:
    bool judgeSquareSum(int c) {
        int limit = sqrt(c);
        for(int i = 0; i <= c; i++){
            
            long sj = c - (i*1LL*i);
            if(sj < 0 ) continue;
            int j = sqrt(sj);
            
            if( (i*1LL*i) + (j*1LL*j) == c ){
                return true;
            }
        }
        return false;
    }
};