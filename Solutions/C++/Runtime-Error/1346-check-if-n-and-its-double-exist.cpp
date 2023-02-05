/*
Problem Title: 1346 - Check If N and Its Double Exist
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/check-if-n-and-its-double-exist
Submission Url: https://leetcode.com/problems/check-if-n-and-its-double-exist/submissions/890998676
*/

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        bool ans = false;
        for(int i = 0 ; i < arr.size(); i++) {
            int lo  = i+1, hi = arr.size()-1, target = arr[i]<<1;
            while(lo <= hi) {
                int mid = lo + ((hi-lo)>>1);
                if(arr[mid] == target) {
                    ans = true;
                }
                if(arr[mid] > target) {
                    hi = mid -1;
                } else {
                    lo = mid + 1;
                }
            }
            if(ans){
                break;
            }
        }
        return ans;
    }
};