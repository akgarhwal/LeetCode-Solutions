/*
Problem Title: 1004 - Max Consecutive Ones III
Lang: C++
Runtime: 60 ms
Memory: 55.3 MB
Problem Url: https://leetcode.com/problems/max-consecutive-ones-iii
Submission Url: https://leetcode.com/problems/max-consecutive-ones-iii/submissions/514852555
*/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int f = 0, s = 0, rk = k, ans = 0;
        int N = nums.size();
        
        while( f < N ){
            while(s < N and (rk > 0 or (rk == 0 and nums[s] == 1))){
                if(nums[s] == 0){
                    rk--;
                }
                s++;
            }
            ans = max(ans, s-f);
            if(nums[f]==0){
                rk++;
            }
            f++;
        }
        return ans;
    }
};