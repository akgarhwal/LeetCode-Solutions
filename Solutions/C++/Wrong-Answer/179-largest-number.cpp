/*
Problem Title: 179 - Largest Number
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/largest-number
Submission Url: https://leetcode.com/problems/largest-number/submissions/306444806
*/

bool mySort(int x, int y){
    
    string xy = to_string(x) + to_string(y);
    string yx = to_string(y) + to_string(x);
    
    return xy > yx;
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        sort(nums.begin(), nums.end(), mySort);
        
        string res = "";
        for(auto num: nums){
            res += to_string(num);
        }
        return res;
    }
};