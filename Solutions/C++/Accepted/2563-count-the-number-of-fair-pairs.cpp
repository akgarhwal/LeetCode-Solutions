/*
Problem Title: 2563 - Count the Number of Fair Pairs
Lang: C++
Runtime: 302 ms
Memory: 53.7 MB
Problem Url: https://leetcode.com/problems/count-the-number-of-fair-pairs
Submission Url: https://leetcode.com/problems/count-the-number-of-fair-pairs/submissions/896276129
*/

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        
        long long ans = 0;
        
        for(int i= 0; i < nums.size(); i++) {
            int x = lower - nums[i];
            int y = upper - nums[i];
            // cout<<"X : "<<x<<" Y : "<<y<<endl;
            
            int lb = lower_bound(nums.begin(), nums.end(), x) - nums.begin();
            int ub = upper_bound(nums.begin(), nums.end(), y) - nums.begin();
            
            // cout<<i<<" - "<<nums[i]<<" - lb: "<<lb<<", ub: "<<ub<<", alb: "<<max(lb,i)<<endl;
            
            if(lb != ub){
                // if(ub == nums.size()){
                //     ub--;
                // }
                
                if((ub - max(lb,i+1)) > 0){
                    ans += (ub - max(lb,i+1));
                }
            }
            // cout<<"Ans: "<<ans<<endl;
        }
        
        return ans;
    }
};