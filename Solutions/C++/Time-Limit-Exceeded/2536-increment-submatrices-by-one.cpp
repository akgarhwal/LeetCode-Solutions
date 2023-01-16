/*
Problem Title: 2536 - Increment Submatrices by One
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/increment-submatrices-by-one
Submission Url: https://leetcode.com/problems/increment-submatrices-by-one/submissions/878336380
*/

class Solution {
public:
    
    void updateMat(vector<int>& query, vector<vector<int>>& mat) {
        for(int i = query[0]; i <= query[2]; i++) {
            for(int j = query[1]; j <= query[3]; j++) {
                mat[i][j] += 1;
            }
        }
    }
    
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> mat(n, vector<int>(n,0));
        
        for(vector<int> query : queries){
            
            updateMat(query, mat);
            
        }
        return mat;
    }
};