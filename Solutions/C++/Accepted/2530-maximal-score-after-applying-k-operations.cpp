/*
Problem Title: 2530 - Maximal Score After Applying K Operations
Lang: C++
Runtime: 293 ms
Memory: 75.8 MB
Problem Url: https://leetcode.com/problems/maximal-score-after-applying-k-operations
Submission Url: https://leetcode.com/problems/maximal-score-after-applying-k-operations/submissions/873817550
*/

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long maxScore = 0;
        
        priority_queue<int> pq;
        for(int num : nums){
            pq.push(num);
        }
        
        while (k--) {
            int maxNum = pq.top(); pq.pop();
            maxScore += maxNum;
            pq.push(ceil(maxNum/3.0));
        }
        return maxScore;    
    }
};