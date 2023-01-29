/*
Problem Title: 852 - Peak Index in a Mountain Array
Lang: C++
Runtime: 156 ms
Memory: 59.8 MB
Problem Url: https://leetcode.com/problems/peak-index-in-a-mountain-array
Submission Url: https://leetcode.com/problems/peak-index-in-a-mountain-array/submissions/886557265
*/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int st = 0, end = arr.size()-1;

        while(st <= end){

            int mid = st + ((end-st)>>1);
            if(mid == 0 or mid == arr.size()-1){
                return mid;
            }

            if(arr[mid-1] < arr[mid]  and arr[mid] > arr[mid+1]) {
                return mid;
            }

            if(arr[mid-1] < arr[mid]) {
                st = mid + 1;
            } else {
                end = mid;
            }
        }
        return end;
    }
};