/*
Problem Title: 2011 - Final Value of Variable After Performing Operations
Lang: C++
Runtime: 22 ms
Memory: 14 MB
Problem Url: https://leetcode.com/problems/final-value-of-variable-after-performing-operations
Submission Url: https://leetcode.com/problems/final-value-of-variable-after-performing-operations/submissions/849152492
*/

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for( string ops : operations) {
            if(ops[0] == 'X'){
                if(ops[1] == '-'){
                    x--;
                }
                else{
                    x++;
                }
            }
            else{
                if(ops[0] == '-'){
                    x--;
                }
                else{
                    x++;
                }
            }
        }
        return x;
    }
};