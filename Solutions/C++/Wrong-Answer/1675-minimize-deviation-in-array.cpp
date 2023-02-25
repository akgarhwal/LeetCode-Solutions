/*
Problem Title: 1675 - Minimize Deviation in Array
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/minimize-deviation-in-array
Submission Url: https://leetcode.com/problems/minimize-deviation-in-array/submissions/903884447
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

        int counter = 1e3;

        int count2 = 0;

        while(counter--) {
            
            int mi = *pq.begin(), mx = *pq.rbegin();
            ans = min(ans, (mx-mi));

            // cout<<mi <<" - "<<mx<<endl;
            int new_mi = mi, new_mx = mx;

            if( mi&1 and (count2 == 0 or count2 == 2)) {
                new_mi = new_mi<<1;
            }
            if(!(mx&1) and (count2 == 1 or count2 == 2)) {
                new_mx = new_mx>>1;
            }

            count2 = (count2 + 1) % 3;
            // cout<<new_mi <<" = "<<new_mx<<endl;
            pq.insert(new_mi);
            pq.insert(new_mx);

            removeNum(pq, mi);
            removeNum(pq, mx);
        }

        return ans;
    }
};

//[399,908,648,357,693,502,331,649,596,698]
// 698-357
