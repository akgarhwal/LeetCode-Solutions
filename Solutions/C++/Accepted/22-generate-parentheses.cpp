/*
Problem Title: 22 - Generate Parentheses
Lang: C++
Runtime: 4 ms
Memory: 13.5 MB
Problem Url: https://leetcode.com/problems/generate-parentheses
Submission Url: https://leetcode.com/problems/generate-parentheses/submissions/508683279
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(n,0,0,"",ans);
        return ans;
    }
    void solve(int n, int o, int c, string seq, vector<string> &ans ) {
        if(c == n){
            ans.push_back(seq);
            return;
        }
        if(o < n){
            solve(n,o+1,c,seq+"(",ans);
        }
        if(c < o){
            solve(n,o,c+1,seq+")",ans);
        }
    }
};