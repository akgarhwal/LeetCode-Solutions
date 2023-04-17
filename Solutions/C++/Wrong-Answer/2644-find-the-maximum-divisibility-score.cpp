/*
Problem Title: 2644 - Find the Maximum Divisibility Score
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/find-the-maximum-divisibility-score
Submission Url: https://leetcode.com/problems/find-the-maximum-divisibility-score/submissions/934658162
*/

class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int ans = divisors[0], score = 0, maxScore = 0;
        
        for(int i = 0; i < divisors.size(); i++) {
            
            for(int j = 0; j < nums.size(); j++) {
                
                if( (nums[j] % divisors[i]) == 0) {
                    score += 1;
                }
            }
            
            if(score > maxScore) {
                ans = divisors[i];
                maxScore = score;
            }
        }
         
        
        
        return ans;
    }
};