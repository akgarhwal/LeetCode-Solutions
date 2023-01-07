/*
Problem Title: 386 - Lexicographical Numbers
Lang: C++
Runtime: 72 ms
Memory: 11 MB
Problem Url: https://leetcode.com/problems/lexicographical-numbers
Submission Url: https://leetcode.com/problems/lexicographical-numbers/submissions/308277286
*/

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        
        for(int num = 1; num <= 9; num++){
            dfs(num, ans, n);
        }
        
        return ans;
    }
    
    void dfs(int num, vector<int>& ans, int limit){
        if(num > limit) return;
        
        ans.push_back(num);
        
        for(int ind = 0; ind <= 9; ind++){
            
            dfs(num*10+ind, ans, limit);
            
        }
    }
};