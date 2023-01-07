/*
Problem Title: 221 - Maximal Square
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/maximal-square
Submission Url: https://leetcode.com/problems/maximal-square/submissions/603007971
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = n== 0 ? 0 : matrix[0].size();
        int ans = 0;
        vector<vector<int>> mat(n, vector<int>(m,0));
        for(int i = 0; i < n; i++){
            mat[i][0] = matrix[i][0] == '1' ? 1 : 0;
        }
        for(int i = 0; i < m; i++){
            mat[0][i] = matrix[0][i] == '1' ? 1 : 0;
        }
        for(int i = 1; i < n; i++){
            
            for(int j = 1; j < m; j++){
                
                if(matrix[i][j] == '1'){
                    
                    int mi = min( {mat[i-1][j], mat[i][j-1], mat[i-1][j-1]} );
                    mat[i][j] = mi + 1;
                    ans = max(mi+1, ans);
                }
                
            }
        }
        return ans*ans;
    }
};