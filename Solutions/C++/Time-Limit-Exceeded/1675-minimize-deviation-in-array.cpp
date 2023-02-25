/*
Problem Title: 1675 - Minimize Deviation in Array
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/minimize-deviation-in-array
Submission Url: https://leetcode.com/problems/minimize-deviation-in-array/submissions/903878017
*/

class Solution {
public:

    void removeNum(multiset<int>& pq, int num) {
        auto it = pq.find(num); 
        if (it != pq.end()) {
            pq.erase(it); 
        }
    }

    int minimumDeviation(vector<int>& nums) {
        int ans = INT_MAX;
        multiset<int> pq;

        for(int num : nums) {
            pq.insert(num);
        }

        while(true) {
            
            int mi = *pq.begin(), mx = *pq.rbegin();
            ans = min(ans, (mx-mi));

            // cout<<mi <<" - "<<mx<<endl;
            int new_mi = mi, new_mx = mx;

            if( mi&1 ) {
                new_mi = mi<<1;
            }
            if(!(mx&1)) {
                new_mx = mx>>1;
            }

            if(new_mi == mi and new_mx == mx){
                break;
            }

            pq.insert(new_mi);
            pq.insert(new_mx);

            removeNum(pq, mi);
            removeNum(pq, mx);
        }

        return ans;
    }
};