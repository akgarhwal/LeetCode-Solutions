/*
Problem Title: 1702 - Maximum Binary String After Change
Lang: C++
Runtime: 168 ms
Memory: 40.8 MB
Problem Url: https://leetcode.com/problems/maximum-binary-string-after-change
Submission Url: https://leetcode.com/problems/maximum-binary-string-after-change/submissions/434775210
*/

class Solution {
public:
    string maximumBinaryString(string binary) {
        int left_zero = 0, right_zero = binary.size()-1;
        while(left_zero < binary.size() and binary[left_zero] == '1'){
            left_zero += 1;
        }
        while(right_zero > 0 and binary[right_zero] == '1'){
            right_zero -= 1;
        }

        if(left_zero == binary.size()) {
            return binary;
        }
        
        int count = 0;
        while(left_zero < right_zero){
            if(binary[left_zero] == '1') count++;
            left_zero += 1;
        }
        int i = 0;
        while(i < binary.size()){
            if(i == right_zero-count){
                binary[i] = '0';
            }
            else{
                binary[i] = '1';
            }
            i+=1;
        }
        return binary;
    }
};