/*
Problem Title: 1675 - Minimize Deviation in Array
Lang: C++
Runtime: 569 ms
Memory: 56.8 MB
Problem Url: https://leetcode.com/problems/minimize-deviation-in-array
Submission Url: https://leetcode.com/problems/minimize-deviation-in-array/submissions/904039867
*/

class Solution {
public:

    int minimumDeviation(vector<int>& nums) {
        int ans = INT_MAX, mi = INT_MAX;
        priority_queue<int> pq;

        for(int num : nums) {
            if( (num&1) ) {
                num = num<<1;
            }
            mi = min(mi, num);
            pq.push(num);
        }

        while(!pq.empty()) {
            
            int top = pq.top();
            pq.pop();
            
            ans = min(ans, abs(top-mi));

            if( (top&1) == 0) {
                top = top >> 1;
                pq.push(top);
                mi = min(mi, top);
            } else {
                break;
            }
        }

        return ans;
    }
};
