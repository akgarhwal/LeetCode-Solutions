/*
Problem Title: 1431 - Kids With the Greatest Number of Candies
Lang: C++
Runtime: 0 ms
Memory: 8.8 MB
Problem Url: https://leetcode.com/problems/kids-with-the-greatest-number-of-candies
Submission Url: https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/submissions/885114009
*/

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mx = INT_MIN;
        for(int x : candies) {
            mx = max(mx, x);
        }
        vector<bool> ans(candies.size(), false);

        for(int i=0; i < candies.size(); i++) {
            if(candies[i] + extraCandies >= mx) {
                ans[i] = true;
            }
        }
        return ans;
    }
};