/* Question: Product of Array Except Self
 * Lang: cpp
 * Runtime: 42 ms
 * Memory: 25.6 MB
 * Question Url: https://leetcode.com/problems/product-of-array-except-self
 * Submission Url:
 * https://leetcode.com/problems/product-of-array-except-self/submissions/593212709
 */

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pfs;
        int product = 1;
        for(int x : nums){
            product *= x;
            pfs.push_back(product);
        }
        vector<int> result(nums.size());
        product = 1;
        for(int i = nums.size()-1; i>=0; i--){
            
            if(i > 0)
                result[i] = product * pfs[i-1];
            else
                result[i] = product;
            
            product *= nums[i];
        }
        return result;
    }
};
