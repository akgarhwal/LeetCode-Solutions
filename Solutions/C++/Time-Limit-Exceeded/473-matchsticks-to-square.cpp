/*
Problem Title: 473 - Matchsticks to Square
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/matchsticks-to-square
Submission Url: https://leetcode.com/problems/matchsticks-to-square/submissions/508222595
*/

class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        for(int x : matchsticks){
            sum += x;
        }
        int side = sum/4;
        if(side*4 != sum){
            return false;
        }
        return solve(matchsticks, 0, 0, 0, 0, 0, side);
    }
   
    bool solve(vector<int>& matchsticks, int i, int a, int b, int c, int d, int side){
        if(i ==  matchsticks.size()){
            if(a == b and b == c and c == d and d == a){
                return true;
            }
            return false;
        }
        if(side < a or side < b or side < c or side < d){
            return false;
        }
        bool ans = false;
        ans |= solve(matchsticks, i+1, matchsticks[i]+a, b,c,d, side);
        if(!ans){
            ans |= solve(matchsticks, i+1, a,b+matchsticks[i],c,d,side);
        }
        if(!ans){
           ans |= solve(matchsticks, i+1, a,b,c+matchsticks[i],d,side);
        }
        if(!ans){
           ans |= solve(matchsticks, i+1, a,b,c,d+matchsticks[i],side);
        }
        
        return ans;
    }
};