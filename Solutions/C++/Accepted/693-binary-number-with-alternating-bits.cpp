/*
Problem Title: 693 - Binary Number with Alternating Bits
Lang: C++
Runtime: 0 ms
Memory: 6.1 MB
Problem Url: https://leetcode.com/problems/binary-number-with-alternating-bits
Submission Url: https://leetcode.com/problems/binary-number-with-alternating-bits/submissions/321720184
*/

class Solution {
public:
    bool hasAlternatingBits(int n) {
        vector<int> arr;
        while(n){
            arr.push_back(n%2);
            n = n / 2;
        }
        if(arr.size() < 2){
            return true;
        }
        bool res = true;
        for(int i= 1; i< arr.size(); i++){
            if( arr[i] == arr[i-1] ){
                res = false;
                break;
            }
        }
        return res;
    }
};