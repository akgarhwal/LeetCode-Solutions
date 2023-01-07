/*
Problem Title: 164 - Maximum Gap
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/maximum-gap
Submission Url: https://leetcode.com/problems/maximum-gap/submissions/500354389
*/

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2){
            return 0;
        }
        int mi = INT_MAX, mx = INT_MIN;
        for(int x : nums){
            mi = min(mi, x);
            mx = max(mx, x);
        }
        int interval = ceil((mx-mi) / (double)(nums.size()-1));

        vector<pair<int,int>> bucket(interval, {-1, -1});
        
        for(int num : nums){
            int index = (num-mi)/interval;
            if(bucket[index].first != -1){
                bucket[index].first = min(num, bucket[index].first);
                bucket[index].second = max(num, bucket[index].second);
            }
            else{
                bucket[index] = {num, num};
            }
        }
        int ans = interval;
        for(int i = 1; i < bucket.size(); i++){
            
            ans = max(ans, bucket[i].first - bucket[i-1].second);
            
        }
        return ans;
    }
};