/*
Problem Title: 52 - N-Queens II
Lang: C++
Runtime: 44 ms
Memory: 44.5 MB
Problem Url: https://leetcode.com/problems/n-queens-ii
Submission Url: https://leetcode.com/problems/n-queens-ii/submissions/499760402
*/

class Solution {
public:
    int totalNQueens(int n) {
        vector<string> board = init(n);
        int ans = 0;
        set<string> st;
        solve(board, n, n, ans, 0);
        return ans;
    }
  
    
    void solve(vector<string> &board, int n, int rq, int &ans, int x){     
        if(rq == 0){
            ans += 1;
            return;
        }
        for(int j = 0; j < n;j++){
            if(board[x][j] == '.' and isSafe(board, n, x, j)){
                board[x][j] = 'Q';
                solve(board, n, rq-1, ans, x+1);
                board[x][j] = '.';
            }
        }
    }
    
    bool isSafe(vector<string> board, int n, int x, int y){
        for(int k = 0; k < n; k++){
            if(board[x][k] == 'Q') {
                return false;
            }
        }
        for(int k = 0; k < n; k++){
            if(board[k][y] == 'Q') {
                return false;
            }
        }
        int i = x,j=y;
        
        while( i >= 0 and j >= 0 ) {
            if(board[i][j] == 'Q'){
                return false;
            }
            i = i-1; j = j-1;
        }
        i = x;j=y;
        while( i < n and j < n ) {
            if(board[i][j] == 'Q'){
                return false;
            }
            i = i+1; j = j+1;
        }
        i = x;j=y;
        while( i < n and j >= 0 ) {
            if(board[i][j] == 'Q'){
                return false;
            }
            i = i+1; j = j-1;
        }
        i = x;j=y;
        while( i >= 0 and j < n ) {
            if(board[i][j] == 'Q'){
                return false;
            }
            i = i-1; j = j+1;
        }
        return true;
    }
    
    vector<string> init(int n){
        vector<string> board;
        for(int i = 0 ; i<n;i++){
            string str = "";
            for(int j = 0; j < n;j++){
                str += ".";
            }
            board.push_back(str);
        }
        
        return board;
    }
};