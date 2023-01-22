/*
Problem Title: 2433 - Find The Original Array of Prefix Xor
Lang: C++
Runtime: 136 ms
Memory: 76 MB
Problem Url: https://leetcode.com/problems/find-the-original-array-of-prefix-xor
Submission Url: https://leetcode.com/problems/find-the-original-array-of-prefix-xor/submissions/882160645
*/

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> ans(pref.size(), 0);
        ans[0] = pref[0];
        for(int i = 1; i < pref.size(); i++) {
            ans[i] = pref[i-1]^pref[i];
        }
        return ans;
    }
};
