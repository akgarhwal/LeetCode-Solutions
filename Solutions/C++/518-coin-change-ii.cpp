/*
Problem Title: 518 - Coin Change II
Lang: C++
Runtime: 8 ms
Memory: 7.3 MB
Problem Url: https://leetcode.com/problems/coin-change-ii
Submission Url: https://leetcode.com/problems/coin-change-ii/submissions/350213932
*/

class Solution {
    
public:
    int f(int a, vector<int>& coins){
        
        vector<int> mem(a+1, 0);
        mem[0] = 1;
        for(int i =0 ;i < coins.size();i++){
            
            for(int j = coins[i]; j <= a;j++){
                
                mem[j] += mem[j - coins[i]];
                
            }
            
        }
        return mem[a];
        
    }
    int change(int amount, vector<int>& coins) {
        return f(amount, coins);
    }
};