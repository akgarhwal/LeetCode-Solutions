/*
Problem Title: 2469 - Convert the Temperature
Lang: C++
Runtime: 0 ms
Memory: 6 MB
Problem Url: https://leetcode.com/problems/convert-the-temperature
Submission Url: https://leetcode.com/problems/convert-the-temperature/submissions/849150667
*/

class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        vector<double> ans;
        ans.push_back(celsius + 273.15);
        ans.push_back(celsius * 1.8 + 32.0);
        return ans;
    }
};