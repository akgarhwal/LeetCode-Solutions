/*
Problem Title: 1423 - Maximum Points You Can Obtain from Cards
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards
Submission Url: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/submissions/491671063
*/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ans = 0, curSum = 0;
        int sz = cardPoints.size();
        for(int i = sz - k; i < sz; i++){
            curSum += cardPoints[i];
        }
        ans = max(ans, curSum);
        for(int i = 0; i < k; i++){
            curSum -= cardPoints[sz - k -i];
            curSum += cardPoints[i];
            ans = max(ans, curSum);
        }
        return ans;
    }
};