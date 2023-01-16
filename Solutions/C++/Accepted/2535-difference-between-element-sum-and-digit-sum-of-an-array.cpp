/*
Problem Title: 2535 - Difference Between Element Sum and Digit Sum of an Array
Lang: C++
Runtime: 19 ms
Memory: 15.8 MB
Problem Url: https://leetcode.com/problems/difference-between-element-sum-and-digit-sum-of-an-array
Submission Url: https://leetcode.com/problems/difference-between-element-sum-and-digit-sum-of-an-array/submissions/878329306
*/

class Solution {
public:
    
    int getDigitSum(int num){
        int sum = 0;
        while(num > 0){
            sum += num%10;
            num = num /10;
        }
        return sum;
    }
    
    int differenceOfSum(vector<int>& nums) {
        int allSum = 0, digitSum = 0;
        for(int num : nums){
            
            allSum += num;
            digitSum += getDigitSum(num);
        }
        return abs(allSum-digitSum);
    }
};