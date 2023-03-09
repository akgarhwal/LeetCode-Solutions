/*
Problem Title: 875 - Koko Eating Bananas
Lang: C++
Runtime: 53 ms
Memory: 19 MB
Problem Url: https://leetcode.com/problems/koko-eating-bananas
Submission Url: https://leetcode.com/problems/koko-eating-bananas/submissions/911154876
*/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans = 1e9, lo = 1, hi = 1e9;

        while( lo <= hi) {
            int mid = lo + ((hi - lo)>>1);

            long long count = 0;
            for(int i = 0; i < piles.size(); i++) {
                count += ceil(piles[i]/(double)mid);
            }

            if(count <= (long long)h) {
                hi = mid - 1;
                ans = min(ans, mid);
            } else {
                lo = mid + 1;
            }
        }

        return ans;
    }
};