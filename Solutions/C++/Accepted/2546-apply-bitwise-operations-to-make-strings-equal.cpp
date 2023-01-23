/*
Problem Title: 2546 - Apply Bitwise Operations to Make Strings Equal
Lang: C++
Runtime: 46 ms
Memory: 13.1 MB
Problem Url: https://leetcode.com/problems/apply-bitwise-operations-to-make-strings-equal
Submission Url: https://leetcode.com/problems/apply-bitwise-operations-to-make-strings-equal/submissions/882793730
*/

class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        int one = 0, zero = 0;
        for(char ch : s){
            if(ch == '1'){
                one++;
            } else {
                zero++;
            }
        }
        int ot = 0, zt = 0;
        for(char ch : target){
            if(ch == '1'){
                ot++;
            } else {
                zt++;
            }
        }
        
        if( (one == 0 and zt == 0) or (zero == 0 and ot == 0) ) {
            return false;
        }
        
        if( (one != 0 and ot == 0) or (one == 0 and ot != 0) or ( one == 0 and zt == 0)) {
            return false;
        }
        
        return true;
    }
};