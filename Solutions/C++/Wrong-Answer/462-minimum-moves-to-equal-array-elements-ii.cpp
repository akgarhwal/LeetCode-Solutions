/*
Problem Title: 462 - Minimum Moves to Equal Array Elements II
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii
Submission Url: https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/submissions/495365057
*/

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int ans = 0;
        long sum = 0;
        for(int x : nums) {
            sum += x;
        }
        long target1 = floor(sum/(double)nums.size());
        cout<<target1<<" ";
        int ans1 = 0, ans2 = 0;
        for(int x : nums){
            ans1 += abs(x - target1);
        }
        long target2 = ceil(sum/(double)nums.size());
        cout<<target2<<" ";
        for(int x : nums){
            ans2 += abs(x - target2);
        }
        
        return min(ans1,ans2);
    }
};