/*
Problem Title: 59 - Spiral Matrix II
Lang: C++
Runtime: 0 ms
Memory: 6.7 MB
Problem Url: https://leetcode.com/problems/spiral-matrix-ii
Submission Url: https://leetcode.com/problems/spiral-matrix-ii/submissions/947555819
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

        vector<vector<int>> matrix(n, vector<int>(n, 0));

        int x = 0, y = 0, m = n-1, count = 1;
        n--;

        while(x <= m and y <= n) {
            
            // top row
            for(int i = y; i <= n; i++) {
                matrix[x][i] = count++;
            }
            x++;
            // right column
            for(int i = x; i <= m; i++) {
                matrix[i][n] = count++;
            }
            n--;
            // bottom row
            if(x <= m) {
                for(int i = n; i >= y; i--) {
                    matrix[m][i] = count++;
                }    
            }
            m--;
            // left column
            if(y <= n) {
                for(int i = m; i >= x; i--) {
                    matrix[i][y] = count++;
                }
            }
            y++;
        }

        return matrix;
    }
};