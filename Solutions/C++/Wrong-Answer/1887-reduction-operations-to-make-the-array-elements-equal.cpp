/*
Problem Title: 1887 - Reduction Operations to Make the Array Elements Equal
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal
Submission Url: https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/submissions/503629917
*/

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        int st = nums[0], eqc = 0, cur = nums[0];
        for(int i = 1; i <nums.size(); i++){
            
            if(nums[i] == st){
                continue;
            }
            if(nums[i] == cur){
                eqc++;
            }
            else{
                cur = nums[i];
                ans += (eqc+1);
            }
            
        }
        ans += (eqc);
        return ans;
    }
};