/*
Problem Title: 474 - Ones and Zeroes
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/ones-and-zeroes
Submission Url: https://leetcode.com/problems/ones-and-zeroes/submissions/487892024
*/

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int ans = 0;
        for(string str : strs) {

            int one_count = 0;
            for(char ch : str){
                one_count += (ch == '1' ? 1 : 0);
            }
            int zero_count = str.size() - one_count;

            if(zero_count <= m and one_count <= n){
                ans++;
            }

        }
        return ans;
    }
};