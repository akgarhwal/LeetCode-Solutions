/*
Problem Title: 944 - Delete Columns to Make Sorted
Lang: C++
Runtime: 49 ms
Memory: 12.2 MB
Problem Url: https://leetcode.com/problems/delete-columns-to-make-sorted
Submission Url: https://leetcode.com/problems/delete-columns-to-make-sorted/submissions/870071365
*/

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans = 0, R = strs.size(), C = strs[0].size();
        for(int i = 0; i < C; i++) {
            char ch = 'a';
            for(int j = 0 ; j < R; j++) {
                if(ch > strs[j][i]) {
                    ans += 1;
                    break;
                }
                ch = strs[j][i];
            }
        }
        return ans;
    }
};