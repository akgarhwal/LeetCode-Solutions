/*
Problem Title: 1422 - Maximum Score After Splitting a String
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/maximum-score-after-splitting-a-string
Submission Url: https://leetcode.com/problems/maximum-score-after-splitting-a-string/submissions/330311233
*/

class Solution {
public:
    int maxScore(string s) {
        int zero_so_far = 0, one_so_far =0, total_one = 0;
        for(char ch : s){
            if(ch == '1'){
                total_one++;
            }
        }
        int max_score = 0;
        for(char ch: s){
            if(ch == '0'){
                zero_so_far++;
            }
            else{
                one_so_far++;
            }
            max_score = max(max_score, zero_so_far + total_one - one_so_far);
        }
        return max_score;
    }
};