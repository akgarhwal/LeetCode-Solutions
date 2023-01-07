/*
Problem Title: 2522 - Partition String Into Substrings With Values at Most K
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/partition-string-into-substrings-with-values-at-most-k
Submission Url: https://leetcode.com/problems/partition-string-into-substrings-with-values-at-most-k/submissions/868865111
*/

class Solution {
public:
    int ans;
    void solve(string s, int i, int k, long num, int count) {
        if(i == s.size()) {
            if(num <= k) {
                ans = count;
            }
            return;
        }
        
        if(ans != INT_MAX) {
            return;
        }
        
        int cd = int(s[i] - '0');
        num = num * 10LL + cd;
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