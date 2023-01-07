/*
Problem Title: 55 - Jump Game
Lang: C++
Runtime: 76 ms
Memory: 48.3 MB
Problem Url: https://leetcode.com/problems/jump-game
Submission Url: https://leetcode.com/problems/jump-game/submissions/593690231
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int limit = 0;
        for(int index = 0; index < nums.size(); index++){
            if(limit < index){
               return false;
            }
            limit = max(limit, index + nums[index]);
        }
        return true;
    }
};