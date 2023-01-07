/*
Problem Title: 1375 - Number of Times Binary String Is Prefix-Aligned
Lang: C++
Runtime: 76 ms
Memory: 12.9 MB
Problem Url: https://leetcode.com/problems/number-of-times-binary-string-is-prefix-aligned
Submission Url: https://leetcode.com/problems/number-of-times-binary-string-is-prefix-aligned/submissions/310413135
*/

class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        set<int> st;
        int ans = 0;
        int cur_max = 0;
        for(int i = 0; i<light.size(); i++){
            
            int num = light[i];
            cur_max = max(cur_max, num);
            
            if(i+1 == cur_max){
                ans++;
            }
        }
        return ans;
    }
};