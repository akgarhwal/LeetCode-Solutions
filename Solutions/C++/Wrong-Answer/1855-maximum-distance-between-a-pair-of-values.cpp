/*
Problem Title: 1855 - Maximum Distance Between a Pair of Values
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/maximum-distance-between-a-pair-of-values
Submission Url: https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/submissions/892337562
*/

class Solution {
public:

    bool isOK(vector<int>& nums1, vector<int>& nums2, int d) {

        for(int i=0; i < nums1.size(); i++) {
            if(i+d < nums2.size() and nums1[i] <= nums2[i+d]) {
                return true;
            }
        }
        return false;
    }

    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0, lo = 0, hi = min(nums1.size(), nums2.size());

        while( lo <= hi ) {
            int mid = lo  + (hi-lo)/2;
            if(isOK(nums1, nums2, mid)) {
                ans = max(ans, mid);
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return ans;
    }
};