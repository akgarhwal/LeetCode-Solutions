/*
Problem Title: 2348 - Number of Zero-Filled Subarrays
Lang: C++
Runtime: 162 ms
Memory: 107.6 MB
Problem Url: https://leetcode.com/problems/number-of-zero-filled-subarrays
Submission Url: https://leetcode.com/problems/number-of-zero-filled-subarrays/submissions/919396803
*/

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0LL, count = 0LL;
        
        for(int num : nums){
            
            if(num != 0){
                
                if(count > 0 ){
                    ans += ((count * (count + 1LL))>>1);
                }
                count = 0LL;
            } else {
                count += 1;
            }
        }

        if(count > 0) {
            ans += ((count * (count + 1LL))>>1);
        }
        
        return ans;
    }
};