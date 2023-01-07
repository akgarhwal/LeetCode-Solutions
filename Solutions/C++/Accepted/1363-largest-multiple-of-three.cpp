/*
Problem Title: 1363 - Largest Multiple of Three
Lang: C++
Runtime: 8 ms
Memory: 9.8 MB
Problem Url: https://leetcode.com/problems/largest-multiple-of-three
Submission Url: https://leetcode.com/problems/largest-multiple-of-three/submissions/306438760
*/

class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        
        vector<int> freq(10,0);
        
        for(auto digit: digits){
            freq[digit] += 1;
        }
        
        int sum = accumulate(digits.begin(), digits.end(), 0); 
        
        string ans = "";
        
        if(sum % 3 == 1) {
            
            if(freq[1] > 0){
                freq[1] -= 1;
            }
            else if (freq[4] > 0) {
                freq[4] -= 1;
            }
            else if (freq[7] > 0) {
                freq[7] -= 1;
            }
            
            else if (freq[2] > 1){
                freq[2] -= 2;
            }
            else if(freq[2] > 0 && freq[5] > 0) {
                freq[2] -= 1;
                freq[5] -= 1;
            }
            else if (freq[5] > 1){
                freq[5] -= 2;
            }
            else if(freq[2] > 0 && freq[8] > 0) {
                freq[2] -= 1;
                freq[8] -= 1;
            }
            else if(freq[5] > 0 && freq[8] > 0) {
                freq[5] -= 1;
                freq[8] -= 1;
            }
            else if (freq[8] > 1){
                freq[8] -= 2;
            }
        }
        
        if(sum % 3 == 2) {
            
            if(freq[2] > 0){
                freq[2] -= 1;
            }
            else if (freq[5] > 0) {
                freq[5] -= 1;
            }
            else if (freq[8] > 0) {
                freq[8] -= 1;
            }
            
            else if (freq[1] > 1){
                freq[1] -= 2;
            }
            else if(freq[1] > 0 && freq[4] > 0) {
                freq[1] -= 1;
                freq[4] -= 1;
            }
            else if (freq[4] > 1){
                freq[4] -= 2;
            }
            else if(freq[1] > 0 && freq[7] > 0) {
                freq[1] -= 1;
                freq[7] -= 1;
            }
            else if(freq[4] > 0 && freq[7] > 0) {
                freq[4] -= 1;
                freq[7] -= 1;
            }
            else if (freq[7] > 1){
                freq[7] -= 2;
            }
        }
        
        
        int ind = 9;
        while(ind >= 0){
            
            if(ind == 0 && ans.size() == 0 && freq[ind] > 0){
                ans = "0";
                break;
            }
            
            while(freq[ind] > 0){
                
                ans += (ind + '0');
                freq[ind] -= 1;
            }
            ind -= 1;
        }
        return ans;
    }
};