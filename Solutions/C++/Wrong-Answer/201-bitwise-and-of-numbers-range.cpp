/*
Problem Title: 201 - Bitwise AND of Numbers Range
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/bitwise-and-of-numbers-range
Submission Url: https://leetcode.com/problems/bitwise-and-of-numbers-range/submissions/329077529
*/

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int diff = n-m;
        int i = 0;
        int ans = 0;
        while( i < 32){
            if((m&(1<<i)) > 0 ){
                if(pow(2,i) > diff){
                    ans = ans | (1<<i);
                    cout<<m<<" - "<<n<<" = "<<i<<endl;
                }
            }
            i += 1;
        }
        return ans;
    }
};