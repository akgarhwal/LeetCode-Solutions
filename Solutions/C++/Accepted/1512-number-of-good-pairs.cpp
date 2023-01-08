/*
Problem Title: 1512 - Number of Good Pairs
Lang: C++
Runtime: 0 ms
Memory: 7.4 MB
Problem Url: https://leetcode.com/problems/number-of-good-pairs
Submission Url: https://leetcode.com/problems/number-of-good-pairs/submissions/873497647
*/

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        vector<int> freq(101, 0);
        for(int num : nums){
            freq[num] += 1;
        }
        int ans = 0;
        for(int count : freq){
            if(count >= 2){
                ans += (count * (count-1))/2;
            }
        }
        return ans;
    }
};