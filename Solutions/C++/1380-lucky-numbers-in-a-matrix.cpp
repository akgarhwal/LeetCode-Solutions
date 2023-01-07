/*
Problem Title: 1380 - Lucky Numbers in a Matrix
Lang: C++
Runtime: 48 ms
Memory: 9.5 MB
Problem Url: https://leetcode.com/problems/lucky-numbers-in-a-matrix
Submission Url: https://leetcode.com/problems/lucky-numbers-in-a-matrix/submissions/312561449
*/

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {

        vector<int> res;
        int R = matrix.size();
        int C = matrix[0].size();
        
        for(int i = 0; i < R; i++){
            
            for(int j = 0; j < C; j++ ){
                
                int mi = INT_MAX;
                for(int k = 0; k < C;k++){
                    mi = min(mi, matrix[i][k]);
                }
                
                int mx = INT_MIN;
                for(int k = 0; k < R;k++){
                    mx = max(mx, matrix[k][j]);
                }
                
                if(mi == mx && mi == matrix[i][j]){
                    res.push_back(mi);
                }
                
            }
            
        }
        
        return res;
    }
};