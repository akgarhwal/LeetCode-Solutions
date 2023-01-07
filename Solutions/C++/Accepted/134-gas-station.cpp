/*
Problem Title: 134 - Gas Station
Lang: C++
Runtime: 113 ms
Memory: 72.3 MB
Problem Url: https://leetcode.com/problems/gas-station
Submission Url: https://leetcode.com/problems/gas-station/submissions/873000348
*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int N = gas.size();
        vector<int> arr( N * 2, 0);

        arr[0] = gas[0] - cost[0];
        for(int i = 1; i < N * 2; i++) {
            int j = i >= N ? i - N : i;
            int rf = arr[i-1] > 0 ? arr[i-1] : 0;
            arr[i] = gas[j] - cost[j] + rf; 
        }

        int start = -1, count = 0;
        for(int i = 0; i < 2*N; i++){
            if(arr[i] >= 0) {
                if(start == -1){
                    start = i >= N ? i - N : i;
                }
                count++;
                if(count == N) {
                    return start;
                }
            } else {
                start = -1;
                count = 0;
            }
        }

        return -1;
    }
};