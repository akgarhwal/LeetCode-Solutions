/*
Problem Title: 2652 - Sum Multiples
Lang: C++
Runtime: 4 ms
Memory: 5.8 MB
Problem Url: https://leetcode.com/problems/sum-multiples
Submission Url: https://leetcode.com/problems/sum-multiples/submissions/938165339
*/

class Solution {
public:
    int sumOfMultiples(int n) {
        int ans = 0;
        
        for(int i=1; i <= n; i++) {
            
            if( (i%3) == 0 ){
                ans += i;
                continue;
            }
            if( (i%5)==0 ){
                ans += i;
                continue;
            }
            if( (i%7)==0 ){
                ans += i;
                continue;
            }
        }
        cout<<endl;
        return ans;
    }
};