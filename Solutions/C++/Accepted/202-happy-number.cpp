/*
Problem Title: 202 - Happy Number
Lang: C++
Runtime: 7 ms
Memory: 6.4 MB
Problem Url: https://leetcode.com/problems/happy-number
Submission Url: https://leetcode.com/problems/happy-number/submissions/775666247
*/

class Solution {
public:
    
    int sumOfSqureDigit(int num){
        int res = 0;
         while(num > 0){
            res += (num%10) * (num%10); 
            num  = num / 10;
        }
        return res;
    }
    
    bool isHappy(int n) {
        
        unordered_set<int> mset;
        int num = n;
        while(num != 1){
            
            int new_num = sumOfSqureDigit(num);
        
            if(mset.count(new_num) > 0){
                return false;
            }
            mset.insert(new_num);
            num = new_num;
        }
        return true;
    }
};