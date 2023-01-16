/*
Problem Title: 2536 - Increment Submatrices by One
Lang: C++
Runtime: 478 ms
Memory: 94 MB
Problem Url: https://leetcode.com/problems/increment-submatrices-by-one
Submission Url: https://leetcode.com/problems/increment-submatrices-by-one/submissions/878366716
*/

class Solution {
public:
    
    void updateMat(vector<int>& query, vector<vector<int>>& mat) {
        for(int i = query[0]; i <= query[2]; i++) {
            mat[i][query[1]] += 1;
            mat[i][query[3]+1] -= 1;
        }
    }
    
    
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> mat(n+1, vector<int>(n+1,0));
        
        for(vector<int> query : queries){
            updateMat(query, mat);
        }
        vector<vector<int>> ans(n, vector<int>(n,0));
        
        for(int i = 0; i < n; i++ ) {
            for(int j = 0; j <n; j++) {
                
                if(j == 0){
                    ans[i][j] = mat[i][j];
                }
                
                else{
                    ans[i][j] = ans[i][j-1] + mat[i][j];
                }
            }
        }
        
        return ans;
    }
};