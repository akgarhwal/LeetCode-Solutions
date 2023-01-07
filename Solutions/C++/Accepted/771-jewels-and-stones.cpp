/*
Problem Title: 771 - Jewels and Stones
Lang: C++
Runtime: 0 ms
Memory: 6.1 MB
Problem Url: https://leetcode.com/problems/jewels-and-stones
Submission Url: https://leetcode.com/problems/jewels-and-stones/submissions/333071767
*/

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int ans = 0;
        for(auto stone: S){
            for(auto jewel: J){
                if(stone == jewel){
                    ans += 1;
                    break;
                }
            }
            
        }
        return ans;
    }
};