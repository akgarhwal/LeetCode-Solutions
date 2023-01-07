/*
Problem Title: 970 - Powerful Integers
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/powerful-integers
Submission Url: https://leetcode.com/problems/powerful-integers/submissions/487079332
*/

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> temp;
        for(int i = 0; i < 31; i++) {
            for(int j = 0; j < 31; j++) {
                long num = pow(x, i) + pow(y, j);
                if(num <= bound) {
                    temp.insert(num);
                }
                else{
                    break;
                }
            }
        }
        vector<int> ans(temp.begin(), temp.end());
        return ans;
    }
};