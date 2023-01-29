/*
Problem Title: 852 - Peak Index in a Mountain Array
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/peak-index-in-a-mountain-array
Submission Url: https://leetcode.com/problems/peak-index-in-a-mountain-array/submissions/886556204
*/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int st = 0, end = arr.size()-1;

        while(st <= end){

            int mid = st + ((end-st)>>1);
            if(arr[mid-1] < arr[mid]  and arr[mid] > arr[mid+1]) {
                return mid;
            }

            if(arr[mid-1] < arr[mid]) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return st;
    }
};