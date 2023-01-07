/*
Problem Title: 2522 - Partition String Into Substrings With Values at Most K
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/partition-string-into-substrings-with-values-at-most-k
Submission Url: https://leetcode.com/problems/partition-string-into-substrings-with-values-at-most-k/submissions/868839453
*/

class Solution {
public:
    int ans;
    void solve(string s, int i, int k, int num, int count) {
        // cout<<num<<" - "<<count<<endl;
        if(i == s.size()) {
            if(num <= k) {
                ans = min(ans, count);
            }
            // cout<<num<<" - "<<count<<endl;
            return;
        }
        
        if(ans != INT_MAX or count > ans) {
            return;
        }
        
        int cd = int(s[i] - '0');
        
        num = num * 10 + cd;
            
        if(num <= k) {
            solve(s, i+1, k, num, count);
        }
        else if(cd <= k){
            solve(s, i+1, k, cd, count + 1);
        }
    }
    int minimumPartition(string s, int k) {
        ans = INT_MAX;
        solve(s, 0, k, 0, 1);
        
        return ans == INT_MAX ? -1 : ans;
    }
};