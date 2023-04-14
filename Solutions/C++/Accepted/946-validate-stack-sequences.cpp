/*
Problem Title: 946 - Validate Stack Sequences
Lang: C++
Runtime: 4 ms
Memory: 15.4 MB
Problem Url: https://leetcode.com/problems/validate-stack-sequences
Submission Url: https://leetcode.com/problems/validate-stack-sequences/submissions/933067617
*/

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;

        int i = 0, j = 0;

        while(i < pushed.size()) {

            st.push(pushed[i++]);

            while(!st.empty() and st.top() == popped[j]){
                st.pop();
                j++;
            }
        }

        return j == popped.size();
    }
};