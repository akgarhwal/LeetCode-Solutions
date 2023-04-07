/*
Problem Title: 119 - Pascal's Triangle II
Lang: C++
Runtime: 0 ms
Memory: 6.6 MB
Problem Url: https://leetcode.com/problems/pascals-triangle-ii
Submission Url: https://leetcode.com/problems/pascals-triangle-ii/submissions/928783681
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int n = rowIndex + 1;
        vector<vector<int>> ans;
        vector<int> first(1,1);
        ans.push_back(first);
        
        if(n >= 2){
            first.push_back(1);
            ans.push_back(first);
        }
        
        while( n > 2){
            
            vector<int> row;
            row.push_back(1);
            
            int lr = ans.size();
            
            for(int i=1;i < lr; i++){
                row.push_back(ans[lr-1][i]+ans[lr-1][i-1]);
            }
            row.push_back(1);
            ans.push_back(row);
            n--;
        }
        return ans[rowIndex];
    }
};