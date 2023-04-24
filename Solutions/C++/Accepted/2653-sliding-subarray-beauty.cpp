/*
Problem Title: 2653 - Sliding Subarray Beauty
Lang: C++
Runtime: 2114 ms
Memory: 188.5 MB
Problem Url: https://leetcode.com/problems/sliding-subarray-beauty
Submission Url: https://leetcode.com/problems/sliding-subarray-beauty/submissions/938175399
*/

class Solution {
public:
    
    int get_beauty(unordered_map<int,int>& mp, int x) {
        int count = -50;
        
        while(x) {
            
            if(mp[count] > 0){
                x -= mp[count];
            }
            
            if(x <= 0) {
                return count;
            }
            count++;
            if(count >= 0){
                break;
            }
        }
        
        return 0;
    }
    
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        vector<int> ans;
        unordered_map<int,int> mp;
        
        for(int i = 0; i < k; i++) {
            mp[nums[i]]++;
        }
        
        for(int i = k; i < nums.size(); i++) {
            
            int beauty = get_beauty(mp, x);
            ans.push_back(beauty);
            
            mp[nums[i-k]]--;
            mp[nums[i]]++;
        }
        
        int beauty = get_beauty(mp, x);    
        ans.push_back(beauty);
        
        return ans;
    }
};