/*
Problem Title: 2405 - Optimal Partition of String
Lang: C++
Runtime: 34 ms
Memory: 10.3 MB
Problem Url: https://leetcode.com/problems/optimal-partition-of-string
Submission Url: https://leetcode.com/problems/optimal-partition-of-string/submissions/927841347
*/

class Solution {
public:
    int partitionString(string s) {
        int ans = 0, i = 0;
        vector<int> freq(26, 0);

        while( i < s.size() ) {

            if(freq[s[i]-'a'] > 0) {
                ans += 1;
                for(int x = 0; x < 26; x++) {
                    freq[x] = 0;
                }
                freq[s[i]-'a'] = 1;
            } else {
                freq[s[i]-'a'] += 1;
            }
            i += 1;
        }
        
        return ans + 1;
    }
};