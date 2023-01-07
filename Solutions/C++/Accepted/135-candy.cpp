/*
Problem Title: 135 - Candy
Lang: C++
Runtime: 24 ms
Memory: 17.6 MB
Problem Url: https://leetcode.com/problems/candy
Submission Url: https://leetcode.com/problems/candy/submissions/513985609
*/

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candies(ratings.size(),1);
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }
        int sum = candies[ratings.size() - 1];
        for (int i = ratings.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
            sum += candies[i];
        }
        return sum;
    }
};