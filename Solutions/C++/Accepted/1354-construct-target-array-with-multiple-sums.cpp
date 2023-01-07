/*
Problem Title: 1354 - Construct Target Array With Multiple Sums
Lang: C++
Runtime: 47 ms
Memory: 30.1 MB
Problem Url: https://leetcode.com/problems/construct-target-array-with-multiple-sums
Submission Url: https://leetcode.com/problems/construct-target-array-with-multiple-sums/submissions/729920906
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
        while(!pq.empty()) {
            int top = pq.top(); pq.pop();
            
            int new_top = top - (sum - top);
            
            if(sum-top > 1){
                new_top = top % (sum-top);
            }
            else if (sum-top == 1) {
                new_top = 1;
            }
            
            if(new_top >= top and new_top != 1) {
                return false;
            }
            if(new_top == top){
                return true;
            }

            if(new_top < 1){
                return false;
            }
            sum -= top;
            sum+=new_top;
            pq.push(new_top);
        }
        return true;                
    }
};