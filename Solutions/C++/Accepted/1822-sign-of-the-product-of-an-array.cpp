/*
Problem Title: 1822 - Sign of the Product of an Array
Lang: C++
Runtime: 8 ms
Memory: 10.2 MB
Problem Url: https://leetcode.com/problems/sign-of-the-product-of-an-array
Submission Url: https://leetcode.com/problems/sign-of-the-product-of-an-array/submissions/942948018
*/

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int neg_count = 0;

        for(int num : nums) {
            if(num == 0) {
                return 0;
            }
            neg_count += (num < 0 ? 1 : 0);
        }

        return neg_count%2 ? -1 : 1;
    }
};