/*
Problem Title: 476 - Number Complement
Lang: C++
Runtime: 0 ms
Memory: 6 MB
Problem Url: https://leetcode.com/problems/number-complement
Submission Url: https://leetcode.com/problems/number-complement/submissions/607765530
*/

class Solution {
public:
    int findComplement(int num) {
        int ans = 0, i = 0;
        while(num){
            if((num&1)  == 0){
                ans = ((1 << i) | ans);
            }
            num = num >> 1;
            i++;
        }
        return ans;
    }
};