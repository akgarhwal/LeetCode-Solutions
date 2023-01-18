/*
Problem Title: 926 - Flip String to Monotone Increasing
Lang: C++
Runtime: 51 ms
Memory: 20.1 MB
Problem Url: https://leetcode.com/problems/flip-string-to-monotone-increasing
Submission Url: https://leetcode.com/problems/flip-string-to-monotone-increasing/submissions/879841505
*/

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        if(s.size() <= 1){
            return 1;
        }
        int ans = INT_MAX;
        vector<int> leftOneCount(s.size(), 0), rightZeroCount(s.size(), 0);

        for(int i = 0; i < s.size(); i++){
            if(i == 0){
                leftOneCount[i] = s[i] == '1' ? 1 : 0;
            }
            else{
                leftOneCount[i] = (s[i] == '1' ? 1 : 0) + leftOneCount[i-1];
            }
        }
        for(int i = s.size()-1; i >= 0; i--){
            if(i == s.size()-1){
                rightZeroCount[i] = s[i] == '0' ? 1 : 0;
            }
            else{
                rightZeroCount[i] = (s[i] == '0' ? 1 : 0) + rightZeroCount[i+1];
            }
        }

        ans = min(ans, rightZeroCount[1]);
        for(int i=1; i < s.size()-1; i++) {
            ans = min(ans, (rightZeroCount[i] + leftOneCount[i-1]));
        }
        ans = min(ans, leftOneCount[s.size()-2]);
        return ans;
    }
};