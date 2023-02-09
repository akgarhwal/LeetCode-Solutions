/*
Problem Title: 2553 - Separate the Digits in an Array
Lang: C++
Runtime: 15 ms
Memory: 10.2 MB
Problem Url: https://leetcode.com/problems/separate-the-digits-in-an-array
Submission Url: https://leetcode.com/problems/separate-the-digits-in-an-array/submissions/893710150
*/

class Solution {
public:

    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        int i = 0;

        while( i < nums.size()) {
            string res = to_string(nums[i]);
            int j = 0;
            while(j< res.size()) {
                ans.push_back( res[j] - '0');
                j++;
            }
            i++;
        }

        return ans;
    }
};