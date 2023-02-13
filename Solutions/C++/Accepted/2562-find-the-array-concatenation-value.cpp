/*
Problem Title: 2562 - Find the Array Concatenation Value
Lang: C++
Runtime: 10 ms
Memory: 9.3 MB
Problem Url: https://leetcode.com/problems/find-the-array-concatenation-value
Submission Url: https://leetcode.com/problems/find-the-array-concatenation-value/submissions/896243625
*/

class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long ans = 0;
        int i = 0, j = nums.size()-1;
        
        while( i < j) {
            long long x = nums[i++], y = nums[j--];
            int nod = log10(y) + 1;
        
            ans += (x * pow(10, nod) + y);
        }
        if(i == j) {
            ans += nums[i];
        }
        return ans;
    }
};