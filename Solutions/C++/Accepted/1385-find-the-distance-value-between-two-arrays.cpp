/*
Problem Title: 1385 - Find the Distance Value Between Two Arrays
Lang: C++
Runtime: 22 ms
Memory: 45.9 MB
Problem Url: https://leetcode.com/problems/find-the-distance-value-between-two-arrays
Submission Url: https://leetcode.com/problems/find-the-distance-value-between-two-arrays/submissions/887130581
*/

class Solution {
public:
    bool isAllowed(int num, vector<int> arr, int d) {
        for(int x : arr) {
            if(abs(num - x) <= d){
                return false;
            }
        }
        return true;
    }
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans = 0;
        for(int x : arr1){
            if(isAllowed(x, arr2, d)){
                ans++;
            }
        }
        return ans;
    }
};