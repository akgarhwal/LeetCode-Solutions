/*
Problem Title: 461 - Hamming Distance
Lang: C++
Runtime: 0 ms
Memory: 5.9 MB
Problem Url: https://leetcode.com/problems/hamming-distance
Submission Url: https://leetcode.com/problems/hamming-distance/submissions/362515280
*/

class Solution {
public:
    int hammingDistance(int x, int y) {
        int xo = x ^ y;
        int ans = 0;
        while(xo > 0){
            if((xo&1) > 0){
                ans++;
            }
            xo = xo >> 1;
        }
        return ans;
    }
};