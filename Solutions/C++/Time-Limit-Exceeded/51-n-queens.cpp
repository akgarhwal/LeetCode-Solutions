/*
Problem Title: 51 - N-Queens
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/n-queens
Submission Url: https://leetcode.com/problems/n-queens/submissions/496952584
*/

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board = init(n);
        
        vector<vector<string>> ans;
        set<string> st;
        solve(board, n, n, ans, st);
        
        return ans;
    }
    
    void solve(vector<string> &board, int n, int rq, vector<vector<string>> &ans, set<string> &st){
        
        if(rq == 0){
            string temp="";
            for(int i = 0;i<n;i++){
                temp += board[i];
            }
            if(st.find(temp) == st.end()){
                ans.push_back(board);
                st.insert(temp);
            }
            return;
        }
        
        for(int i = 0;i<n;i++){
            for(int j = 0; j < n;j++){
                if(board[i][j] == '.' and isSafe(board, n, i, j)){
                    board[i][j] = 'Q';
                    solve(board, n, rq-1, ans, st);
                    board[i][j] = '.';
                }
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
    
    void print(vector<string> board, int n){
        for(int i = 0 ; i<n;i++){
            for(int j = 0; j < n;j++){
                cout<<board[i][j];
            }
            cout<<endl;
        }
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