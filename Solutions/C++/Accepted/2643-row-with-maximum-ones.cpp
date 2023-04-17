/*
Problem Title: 2643 - Row With Maximum Ones
Lang: C++
Runtime: 148 ms
Memory: 60.6 MB
Problem Url: https://leetcode.com/problems/row-with-maximum-ones
Submission Url: https://leetcode.com/problems/row-with-maximum-ones/submissions/934655907
*/

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int> ans(2, 0);
        
        for(int i = 0; i < mat.size(); i++) {
            
            int oneCount = 0;
            
            for(int j = 0; j < mat[0].size(); j++) {
                
                oneCount += mat[i][j];
            }
            
            if(oneCount > ans[1]) {
                ans[0] = i;
                ans[1] = oneCount;
            }
        }
        
        return ans;
    }
};