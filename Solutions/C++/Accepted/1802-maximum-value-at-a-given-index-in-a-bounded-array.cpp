/*
Problem Title: 1802 - Maximum Value at a Given Index in a Bounded Array
Lang: C++
Runtime: 4 ms
Memory: 5.9 MB
Problem Url: https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array
Submission Url: https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/submissions/895061373
*/

class Solution {
public:

    bool isOK(int mid, int n, int index, long long maxSum) {
        int left = index;
        int right = n - index - 1;
        long long totalSum = mid + calcSum(mid, left) + calcSum(mid, right);
        return totalSum <= maxSum;
    }

    long long calcSum(long long mid, long long n) {
        long long totalSum = 0;
        if ( n >= (mid-1)) {
            int ex = (n - (mid-1));
            long long temp = 0;
            if(mid > 1 ) {
                n = n - ex;
                temp = ((n*(n+1))/2);
            }
            totalSum = temp + ex; 
        } else {
            long long x = mid - 1 - n;
            totalSum = ((mid*(mid-1))/2) - ((x*(x+1))/2);
        }
        return totalSum;
    }

    int maxValue(int n, int index, int maxSum) {

        int lo = 1, hi = maxSum, ans = INT_MIN;

        while( lo <= hi ) {
            int mid = lo + (hi - lo)/2;
            if(isOK(mid, n, index, maxSum)) {
                ans = max(ans, mid);
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return ans;
    }
};