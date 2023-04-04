/*
Problem Title: 2605 - Form Smallest Number From Two Digit Arrays
Lang: C++
Runtime: 4 ms
Memory: 21.7 MB
Problem Url: https://leetcode.com/problems/form-smallest-number-from-two-digit-arrays
Submission Url: https://leetcode.com/problems/form-smallest-number-from-two-digit-arrays/submissions/927206133
*/

class Solution {
public:

    bool isDigitPresent(int num, vector<int>& arr) {

        while(num) {
            int digit = num%10;

            for(int i = 0; i < arr.size(); i++) {
                if(digit == arr[i]){
                    return true;
                }
            }
            num = num / 10;
        }
        return false;
    }

    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        int ans = 1;
        
        while(ans <= 100) {

            if(isDigitPresent(ans, nums1) and isDigitPresent(ans, nums2)){
                break;
            }
            ans += 1;
        }
        return ans;
    }
};