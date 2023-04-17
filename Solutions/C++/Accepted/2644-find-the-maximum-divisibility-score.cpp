/*
Problem Title: 2644 - Find the Maximum Divisibility Score
Lang: C++
Runtime: 1087 ms
Memory: 29.5 MB
Problem Url: https://leetcode.com/problems/find-the-maximum-divisibility-score
Submission Url: https://leetcode.com/problems/find-the-maximum-divisibility-score/submissions/934659059
*/

class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int ans = divisors[0], maxScore = 0;
        
        for(int i = 0; i < divisors.size(); i++) {
            
            int score = 0;
            for(int j = 0; j < nums.size(); j++) {
                
                if( (nums[j] % divisors[i]) == 0) {
                    score += 1;
                }
            }
            
            if(score == maxScore) {
                ans = min(ans, divisors[i]);
            }
            
            if(score > maxScore) {
                ans = divisors[i];
                maxScore = score;
            }
        }
         
        return ans;
    }
};