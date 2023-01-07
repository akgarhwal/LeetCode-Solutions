/*
Problem Title: 525 - Contiguous Array
Lang: C++
Runtime: 304 ms
Memory: 83 MB
Problem Url: https://leetcode.com/problems/contiguous-array
Submission Url: https://leetcode.com/problems/contiguous-array/submissions/344863109
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ans = 0, counter = 0;
        unordered_map<int,int> mp;
        mp[0] = -1;
        for(int i = 0;i < nums.size(); i++){
            if( nums[i] == 1 ){
                counter += 1;
            }
            else{
                counter -= 1;
            }
            if(mp.count(counter) == 0){
                mp[counter] = i;
            }
            else{
                ans = max(ans, i - mp[counter]);
            }
        }
        return ans;
    }
};