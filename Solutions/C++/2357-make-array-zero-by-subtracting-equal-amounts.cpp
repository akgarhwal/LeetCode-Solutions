/*
Problem Title: 2357 - Make Array Zero by Subtracting Equal Amounts
Lang: C++
Runtime: 0 ms
Memory: 8.3 MB
Problem Url: https://leetcode.com/problems/make-array-zero-by-subtracting-equal-amounts
Submission Url: https://leetcode.com/problems/make-array-zero-by-subtracting-equal-amounts/submissions/764886868
*/

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        set<int> st;
        for(int num : nums){
            if(num != 0){
                st.insert(num);
            }
        }
        return st.size();
    }
};