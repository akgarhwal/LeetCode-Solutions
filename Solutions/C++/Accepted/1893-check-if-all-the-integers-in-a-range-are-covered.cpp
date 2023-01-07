/*
Problem Title: 1893 - Check if All the Integers in a Range Are Covered
Lang: C++
Runtime: 4 ms
Memory: 8.8 MB
Problem Url: https://leetcode.com/problems/check-if-all-the-integers-in-a-range-are-covered
Submission Url: https://leetcode.com/problems/check-if-all-the-integers-in-a-range-are-covered/submissions/506814456
*/

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        
        vector<int> cov(right-left+1, 0);
        
        for(int i=0;i < ranges.size(); i++){
                
            for(int x = ranges[i][0]; x <= ranges[i][1]; x++){
                if(x >= left and x <= right){
                    cov[x - left] = 1;
                }
            }
                
        }
        
        for(int i =0 ; i < cov.size(); i++){
            if(cov[i] == 0){
                return false;
            }
        }
        return true;
    }
};