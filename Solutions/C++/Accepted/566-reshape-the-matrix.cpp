/*
Problem Title: 566 - Reshape the Matrix
Lang: C++
Runtime: 12 ms
Memory: 10.8 MB
Problem Url: https://leetcode.com/problems/reshape-the-matrix
Submission Url: https://leetcode.com/problems/reshape-the-matrix/submissions/518014511
*/

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int R = mat.size();
        int C = mat[0].size();
        
        if(R*C != r*c){
            return mat;
        }
        
        vector<vector<int>> res(r, vector<int>(c));
        
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                
                int nr = getNewRow(i, j, C, c);
                int nc = getNewCol(i, j, C, c);
                res[nr][nc] = mat[i][j];
            }
        }        
        return res;
    }
    int getNewRow(int i, int j, int C, int c){
        int num = i*C + j;
        return num/c;
    }
    int getNewCol(int i, int j, int C, int c){
        int num = i*C + j;
        return num%c;
    }
};