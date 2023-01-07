/*
Problem Title: 576 - Out of Boundary Paths
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/out-of-boundary-paths
Submission Url: https://leetcode.com/problems/out-of-boundary-paths/submissions/748241430
*/

class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int ans = 0;
        for(int i = 1; i <= maxMove; i++){
            ans += solve(m, n, startRow, startColumn, i);
            cout<<i <<" -> "<<ans<<endl;
        }
        return ans;
    }
    bool canMove(int m, int n, int x, int y){
        if( x < 0 or y < 0 or x >= m or y >= n){
            return false;
        }

        return true;
    }
    
    int solve(int m, int n, int x, int y, int move){
        cout<<x<<","<<y<<" => "<<move<<endl;
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
            return count;
        }
        
        int ans = 0;
        
        if(canMove(m,n,x-1,y)==true){
            ans += solve(m,n,x-1,y,move-1);
        }
        if(canMove(m,n,x+1,y)){
            ans += solve(m,n,x+1,y,move-1);
        }
        if(canMove(m,n,x,y-1)){
            ans += solve(m,n,x,y-1,move-1);
        }
        if(canMove(m,n,x,y+1)){
            ans += solve(m,n,x,y+1,move-1);
        }
        
        
        return ans;
    }
};
