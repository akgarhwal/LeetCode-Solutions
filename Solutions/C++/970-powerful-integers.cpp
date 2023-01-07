/*
Problem Title: 970 - Powerful Integers
Lang: C++
Runtime: 4 ms
Memory: 6.6 MB
Problem Url: https://leetcode.com/problems/powerful-integers
Submission Url: https://leetcode.com/problems/powerful-integers/submissions/487083381
*/

class Solution {
public:
    
    long pow1(int x, int y, int bound) {
        
        if(y == 0) return 1;
        
        long ans = pow1(x, y/2, bound);

        if(ans == -1) return ans;
        
        if(ans * ans > (long)bound) return -1;
        
        if(y%2 == 0){
            return ans*ans;
        }
        
        return ans*ans*x;        
    }
    
    
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> temp;
        for(int i = 0; i < 31; i++) {
            for(int j = 0; j < 31; j++) {
                long num1 = pow1(x, i, bound);
                long num2 = pow1(y, j, bound);
                
                if(num1 == -1 or num2 == -1) {
                    break;
                }
                
                if(num1 <= bound && num2 <= bound && num1 + num2 <= (long)bound) {
                    temp.insert(num1+num2);
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