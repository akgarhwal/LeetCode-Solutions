/*
Problem Title: 54 - Spiral Matrix
Lang: C++
Runtime: 2 ms
Memory: 6.9 MB
Problem Url: https://leetcode.com/problems/spiral-matrix
Submission Url: https://leetcode.com/problems/spiral-matrix/submissions/947261884
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> ans;
        int x = 0, y = 0, m = matrix.size()-1, n = matrix[0].size()-1;

        while(x <= m and y <= n) {
            
            // top row
            for(int i = y; i <= n; i++) {
                ans.push_back(matrix[x][i]);
            }
            x++;
            // right column
            for(int i = x; i <= m; i++) {
                ans.push_back(matrix[i][n]);
            }
            n--;
            // bottom row
            if(x <= m) {
                for(int i = n; i >= y; i--) {
                    ans.push_back(matrix[m][i]);
                }    
            }
            m--;
            // left column
            if(y <= n) {
                for(int i = m; i >= x; i--) {
                    ans.push_back(matrix[i][y]);
                }
            }
            y++;
        }

        return ans;
    }
};