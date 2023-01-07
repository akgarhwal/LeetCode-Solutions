/*
Problem Title: 2522 - Partition String Into Substrings With Values at Most K
Lang: C++
Runtime: 9 ms
Memory: 9 MB
Problem Url: https://leetcode.com/problems/partition-string-into-substrings-with-values-at-most-k
Submission Url: https://leetcode.com/problems/partition-string-into-substrings-with-values-at-most-k/submissions/868868228
*/

class Solution {
public:

    int minimumPartition(string s, int k) {
        int ans = 0;
        long num = 0;
        for(int i = 0; i < s.size(); i++) {
            int cd = int(s[i] - '0');
            
            if(cd > k) {
                ans = -1;
                break;
            }

            num = num * 10LL + cd;
            if(num > k) {
                num = cd;
                ans += 1;
            }
        }
        return ans != -1 ? ans + 1 : ans;
    }
};