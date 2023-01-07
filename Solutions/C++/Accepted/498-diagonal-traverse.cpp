/*
Problem Title: 498 - Diagonal Traverse
Lang: C++
Runtime: 40 ms
Memory: 18.8 MB
Problem Url: https://leetcode.com/problems/diagonal-traverse
Submission Url: https://leetcode.com/problems/diagonal-traverse/submissions/434624096
*/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int nr = matrix.size(), nc = 0, count = 0, x = 0, y = 0, dir = 1;
        nc = nr > 0 ? matrix[0].size() : 0;
        vector<int> ans;
        while(count < (nr*nc)){
            ans.push_back(matrix[x][y]);
            if(dir == 1){
                if(x == 0 and y < (nc-1)){
                    y++;
                    dir = dir*-1;
                }
                else if( y == (nc-1)){
                    x++;
                    dir = dir*-1;
                }
                else{
                    x--;y++;
                }
            }
            else{
                if(y == 0 and x < (nr-1)){
                    x++;
                    dir = dir*-1;
                }
                else if(x == nr-1){
                    y++;
                    dir = dir*-1;
                }
                else{
                    x++;y--;
                };
            }
            
            count+=1;
        }
        return ans;
    }
};