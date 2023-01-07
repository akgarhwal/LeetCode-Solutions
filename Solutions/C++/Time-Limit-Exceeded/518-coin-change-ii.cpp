/*
Problem Title: 518 - Coin Change II
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/coin-change-ii
Submission Url: https://leetcode.com/problems/coin-change-ii/submissions/350212299
*/

class Solution {
    
public:
    vector<int> test;
    unordered_map<int,int> mp;
    int f(int a, vector<int>& coins, int i){
        if(a==0){
            return 1;
        }
        if( a < 0 or i == coins.size()){
            return 0;
        }
        
        
        mp[a] = f(a-coins[i], coins, i) + f(a, coins, i+1);
        return mp[a];
    }
    int change(int amount, vector<int>& coins) {
        mp.clear();
        return f(amount, coins, 0);
    }
};