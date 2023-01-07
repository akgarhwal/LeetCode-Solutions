/*
Problem Title: 1696 - Jump Game VI
Lang: C++
Runtime: 272 ms
Memory: 77.3 MB
Problem Url: https://leetcode.com/problems/jump-game-vi
Submission Url: https://leetcode.com/problems/jump-game-vi/submissions/505788077
*/

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<int> d{0};
        for (int i = 1; i < nums.size(); ++i) {
            if (d.front() + k < i)
                d.pop_front();        
            nums[i] += nums[d.front()];
            while (!d.empty() && nums[d.back()] <= nums[i])
                d.pop_back();
            d.push_back(i);
        }
        return nums.back();
    }
};