/*
Problem Title: 2582 - Pass the Pillow
Lang: C++
Runtime: 0 ms
Memory: 6 MB
Problem Url: https://leetcode.com/problems/pass-the-pillow
Submission Url: https://leetcode.com/problems/pass-the-pillow/submissions/909343842
*/

class Solution {
public:
    int passThePillow(int n, int time) {
        int ans = 1, dir = 1;
        while(time--){
            ans += dir;
            if(ans == n){
                dir = -dir;
            }
            if(ans == 1) {
                dir = -dir;
            }
        }
        return ans;
    }
};