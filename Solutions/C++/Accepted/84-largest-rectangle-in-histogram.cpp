/*
Problem Title: 84 - Largest Rectangle in Histogram
Lang: C++
Runtime: 160 ms
Memory: 69.7 MB
Problem Url: https://leetcode.com/problems/largest-rectangle-in-histogram
Submission Url: https://leetcode.com/problems/largest-rectangle-in-histogram/submissions/485511329
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        stack<int> st;
        vector<int> left(heights.size(), 0);
        for(int ind = 0; ind < heights.size(); ind++) {
            while(!st.empty() and heights[st.top()] > heights[ind]) {
                left[st.top()] = ind - st.top() -1;
                st.pop();
            }
            st.push(ind);
        }

        while(!st.empty()) {
            left[st.top()] = heights.size() - st.top() -1;
            st.pop();
        }

        vector<int> right(heights.size(), 0);
        for(int ind = heights.size()-1; ind >= 0; ind--) {
            while(!st.empty() and heights[st.top()] > heights[ind]) {
                right[st.top()] = st.top() - ind -1;
                st.pop();
            }
            st.push(ind);
        }

        while(!st.empty()) {
            right[st.top()] = st.top();
            st.pop();
        }

        int area = INT_MIN;

        for(int i = 0; i < heights.size(); i++) {
            area = max(area, (left[i] + right[i] + 1) * heights[i]);
        }

        return area;

    }
};