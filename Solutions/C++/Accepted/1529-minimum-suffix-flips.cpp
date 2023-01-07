/*
Problem Title: 1529 - Minimum Suffix Flips
Lang: C++
Runtime: 44 ms
Memory: 9.6 MB
Problem Url: https://leetcode.com/problems/minimum-suffix-flips
Submission Url: https://leetcode.com/problems/minimum-suffix-flips/submissions/371747192
*/

class Solution {
public:
    int minFlips(string target) {

        int state = 0;        
        
        for(int i=0;i<target.size();i++){
            
            if((target[i] == '0' and state%2 == 0) || (target[i] == '1' and state%2 == 1)){
                //
            }
            else{
                state++;
            }
            
        }
        
        return state;
    }
};


