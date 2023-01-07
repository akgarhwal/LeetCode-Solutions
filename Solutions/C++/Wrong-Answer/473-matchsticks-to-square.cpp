/*
Problem Title: 473 - Matchsticks to Square
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/matchsticks-to-square
Submission Url: https://leetcode.com/problems/matchsticks-to-square/submissions/508220591
*/

class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        return solve(matchsticks, 0, 0, 0, 0, 0);
    }
   
    bool solve(vector<int>& matchsticks, int i, int a, int b, int c, int d){
        if(i ==  matchsticks.size()){
            if(a == b and b == c and c == d and d == a){
                return true;
            }
            return false;
        }
        bool ans = true;
        ans |= solve(matchsticks, i+1, matchsticks[i]+a, b,c,d);
        ans |= solve(matchsticks, i+1, a,b+matchsticks[i],c,d);
        ans |= solve(matchsticks, i+1, a,b,c+matchsticks[i],d);
        ans |= solve(matchsticks, i+1, a,b,c,d+matchsticks[i]);
        return ans;
    }
};