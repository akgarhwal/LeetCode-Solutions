/*
Problem Title: 2651 - Calculate Delayed Arrival Time
Lang: C++
Runtime: 5 ms
Memory: 5.9 MB
Problem Url: https://leetcode.com/problems/calculate-delayed-arrival-time
Submission Url: https://leetcode.com/problems/calculate-delayed-arrival-time/submissions/938149296
*/

class Solution {
public:
    int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
        return (arrivalTime + delayedTime) % 24;
    }
};