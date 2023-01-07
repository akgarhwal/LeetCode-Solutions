/*
Problem Title: 633 - Sum of Square Numbers
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/sum-of-square-numbers
Submission Url: https://leetcode.com/problems/sum-of-square-numbers/submissions/543924185
*/

class Solution {
public:
    bool judgeSquareSum(int c) {
        int limit = sqrt(c);
        for(int i = 0; i <= c; i++){
            
            int sj = c - (i*i);
            if(sj < 0 ) continue;
            int j = sqrt(sj);
            
            if( (i*i) + (j*j) == c ){
                return true;
            }
        }
        return false;
    }
};