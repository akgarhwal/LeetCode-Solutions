/*
Problem Title: 739 - Daily Temperatures
Lang: C++
Runtime: 56 ms
Memory: 41.5 MB
Problem Url: https://leetcode.com/problems/daily-temperatures
Submission Url: https://leetcode.com/problems/daily-temperatures/submissions/485496327
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> st;
        vector<int> ans(T.size(), 0);

        for(int ind = 0; ind < T.size(); ind++) {

            
            while(!st.empty() and T[st.top()] < T[ind]) {

                ans[st.top()] = ind - st.top();
                st.pop();

            }
            st.push(ind);

        }
        return ans;
    }
};