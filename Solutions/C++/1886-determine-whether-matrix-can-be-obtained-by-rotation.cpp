/*
Problem Title: 1886 - Determine Whether Matrix Can Be Obtained By Rotation
Lang: C++
Runtime: 8 ms
Memory: 11.2 MB
Problem Url: https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation
Submission Url: https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/submissions/503637690
*/

class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        
        
        int R = mat.size();
        int C = mat[0].size();
        
        vector<vector<int>> new_mat(R, vector<int>(C, 0));
        
        
        for(int i=0 ; i< 4;i++){
            
            if(equal(mat, target)){
                return true;
            }
            // roate
            for(int j = 0; j < R; j++){
                int k = C-j-1, l = 0;
                int nr = 0;
                while( nr < R){
                    new_mat[nr++][k] = mat[j][l++];               
                }
                
            }
            
            mat = new_mat;
        }
        return false;
    }
    
    bool equal(vector<vector<int>>& mat, vector<vector<int>>& target){
        int R = mat.size();
        int C = mat[0].size();
        for(int i = 0; i <R;i++){
            for(int j = 0 ;j < C;j++){
                
                if(mat[i][j] != target[i][j]){
                    return false;
                }
                
            }
        }
        return true;
    }
};