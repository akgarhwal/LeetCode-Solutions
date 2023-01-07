/*
Problem Title: 136 - Single Number
Lang: C++
Runtime: 12 ms
Memory: 7.7 MB
Problem Url: https://leetcode.com/problems/single-number
Submission Url: https://leetcode.com/problems/single-number/submissions/318785383
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        
        int result = 0;
        
        for(int i =0; i < nums.size(); i++){
            
            
            result = (result ^ nums[i]);
            
        }
        
        
        return result;
    }
};



