/*
Problem Title: 136 - Single Number
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/single-number
Submission Url: https://leetcode.com/problems/single-number/submissions/318783441
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        
        unordered_map<int,int> mem;
        
        for(int i =0 ;i< nums.size(); i++){
            
            if(mem.count(nums[i]) > 0){
                
                mem.insert({nums[i], mem[nums[i]]+1});
                
            }
            else{
                mem.insert({nums[i], 1});
            }
        }
        
        
        int result = 0;
        for(auto it: mem){
            
            if(it.second == 1){
                result = it.first;
                break;
            }
            
        }
        return result;
        
    }
};