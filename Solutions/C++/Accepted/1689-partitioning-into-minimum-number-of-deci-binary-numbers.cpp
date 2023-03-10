/*
Problem Title: 1689 - Partitioning Into Minimum Number Of Deci-Binary Numbers
Lang: C++
Runtime: 31 ms
Memory: 13.5 MB
Problem Url: https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers
Submission Url: https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/submissions/732345353
*/

class Solution {
public:
    int minPartitions(string n) {
        int ans = 0;
        for(char ch : n){
            ans = max(ans, int(ch - '0'));
        }
        return ans;
    }
};