/*
Problem Title: 118 - Pascal's Triangle
Lang: C++
Runtime: 0 ms
Memory: 6.6 MB
Problem Url: https://leetcode.com/problems/pascals-triangle
Submission Url: https://leetcode.com/problems/pascals-triangle/submissions/750669832
*/

class Solution {
public:
    vector<vector<int>> generate(int n) {
        
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
        return ans;
    }
};