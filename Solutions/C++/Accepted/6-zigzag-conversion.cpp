/*
Problem Title: 6 - Zigzag Conversion
Lang: C++
Runtime: 284 ms
Memory: 87.5 MB
Problem Url: https://leetcode.com/problems/zigzag-conversion
Submission Url: https://leetcode.com/problems/zigzag-conversion/submissions/890654875
*/

class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char>> mat(numRows, vector<char>(1005, ' '));
        int j = 0, ind = 0;

        while(ind < s.size()) {
            for(int i = 0; i < numRows; i++) {
                if(ind >= s.size()) {
                    break;
                }
                mat[i][j] = s[ind++];
            }
            j++;
            for(int i = numRows-2; i > 0; i--) {
                if(ind >= s.size()) {
                    break;
                }
                mat[i][j++] = s[ind++];
            }
        }
        
        string ans = "";
        for(int i = 0; i < numRows; i++) {
            for(int j = 0; j < 1001; j++) {
                if(mat[i][j] != ' '){
                    ans += mat[i][j];
                }
            }
        }

        return ans;
    }
};