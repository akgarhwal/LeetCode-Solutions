/*
Problem Title: 1354 - Construct Target Array With Multiple Sums
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/construct-target-array-with-multiple-sums
Submission Url: https://leetcode.com/problems/construct-target-array-with-multiple-sums/submissions/491139004
*/

class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq;
        long sum = 0;
        for(int x : target) {
            pq.push(x);
            sum += x;
        }
        while(!pq.empty()){
            int top = pq.top(); pq.pop();
            sum -= top;
            if(top == 1){
                return true;
            }
            int ele = top - sum;
            if(ele < 1){
                return false;
            }
            sum+=ele;
            pq.push(ele);
        }
        return true;                
    }
};