/*
Problem Title: 2091 - Removing Minimum and Maximum From Array
Lang: C++
Runtime: 148 ms
Memory: 88.3 MB
Problem Url: https://leetcode.com/problems/removing-minimum-and-maximum-from-array
Submission Url: https://leetcode.com/problems/removing-minimum-and-maximum-from-array/submissions/593707854
*/

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int maxi = 0, mini = 0, maxe = INT_MIN, mine = INT_MAX;
        for(int i=0;i < nums.size();i++){
            if(nums[i] < mine){
                mini = i;
                mine = nums[i];
            }
            if(nums[i] > maxe){
                maxe = nums[i];
                maxi = i;
            }
        }
        int si = min(mini, maxi), li = max(maxi, mini);
        return min(li+1, min((int)nums.size()-si, (int)(si+1+nums.size()-li)));
    }
};