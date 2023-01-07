/*
Problem Title: 1814 - Count Nice Pairs in an Array
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/count-nice-pairs-in-an-array
Submission Url: https://leetcode.com/problems/count-nice-pairs-in-an-array/submissions/475943036
*/

class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int> umap;
        
        for(int x : nums) {
            
            long rx = reversDigits(x);
            umap[rx-x] += 1;
            
        }
        
        long ans = 0;
        
        for(auto pi : umap){
            ans += ((pi.second * 1LL * (pi.second-1))/2);
        }
        return ans;
    }
    long reversDigits(long num)
    {
        long rev_num = 0;
        while (num > 0)
        {
            rev_num = rev_num*10 + num%10;
            num = num/10;
        }
        return rev_num;
    }
};