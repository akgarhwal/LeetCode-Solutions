/*
Problem Title: 1539 - Kth Missing Positive Number
Lang: C++
Runtime: 8 ms
Memory: 9.7 MB
Problem Url: https://leetcode.com/problems/kth-missing-positive-number
Submission Url: https://leetcode.com/problems/kth-missing-positive-number/submissions/889073928
*/

class Solution {
public:
    bool isPresent(vector<int>& arr, int num){
        int low = 0, high = arr.size()-1;

        while(low <= high) {
            int mid = low + (high - low)/2;
            if(arr[mid] == num){
                return true;
            }
            if(arr[mid] < num){
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return false;
    }
    int findKthPositive(vector<int>& arr, int k) {
        int num = 0;
        while(k > 0){
            num++;
            if(!isPresent(arr, num)) {
                k--;
            }
        }
        return num;
    }
};