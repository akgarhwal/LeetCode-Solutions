/*
Problem Title: 576 - Out of Boundary Paths
Lang: C++
Runtime: 956 ms
Memory: 25 MB
Problem Url: https://leetcode.com/problems/out-of-boundary-paths
Submission Url: https://leetcode.com/problems/out-of-boundary-paths/submissions/748265050
*/

class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int ans = 0;
        map<string, int> mp;
        for(int i = 1; i <= maxMove; i++){
            ans = (ans + (solve(m, n, startRow, startColumn, i, mp) % 1000000007)) % 1000000007;
        }
        return ans % 1000000007;
    }
    bool canMove(int m, int n, int x, int y){
        if( x < 0 or y < 0 or x >= m or y >= n){
            return false;
        }
        return true;
    }
    
    int solve(int m, int n, int x, int y, int move, map<string, int> &mp) {
        string key = to_string(x)+","+to_string(y) + "," + to_string(move);
        if(mp.find(key) != mp.end()){
            return mp[key];
        }
        if(move == 1){
            if(x > 0 and x < m-1 and y > 0 and y < n-1){
                return 0;
            }
            int count = 0;
            if(x == 0){
                count += 1;
            }
            if(x == m-1){
                count += 1;
            }
            if(y == 0){
                count += 1;
            }
            if(y == n-1){
                count += 1;
            }
            return mp[key] = count;
        }
        
        int ans = 0;
        if(canMove(m,n,x-1,y)){
            ans = (ans % 1000000007 + (solve(m,n,x-1,y,move-1, mp) % 1000000007)) % 1000000007;
        }
        if(canMove(m,n,x+1,y)){
            ans = (ans % 1000000007 + (solve(m,n,x+1,y,move-1, mp) % 1000000007)) % 1000000007;
        }
        if(canMove(m,n,x,y-1)){
            ans = (ans % 1000000007 + (solve(m,n,x,y-1,move-1, mp) % 1000000007)) % 1000000007;
        }
        if(canMove(m,n,x,y+1)){
            ans = (ans % 1000000007 + (solve(m,n,x,y+1,move-1, mp) % 1000000007)) % 1000000007;
        }
        
        return mp[key] = ans % 1000000007;
    }
};
