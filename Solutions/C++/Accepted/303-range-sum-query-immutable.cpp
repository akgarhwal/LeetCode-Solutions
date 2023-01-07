/*
Problem Title: 303 - Range Sum Query - Immutable
Lang: C++
Runtime: 28 ms
Memory: 17.2 MB
Problem Url: https://leetcode.com/problems/range-sum-query-immutable
Submission Url: https://leetcode.com/problems/range-sum-query-immutable/submissions/871387734
*/

class NumArray {
public:
    vector<int> rsum;
    NumArray(vector<int>& nums) {
        int sum = 0;
        for(int num : nums) {
            sum += num;
            rsum.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0){
            return rsum[right];
        }
        return rsum[right] - rsum[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */