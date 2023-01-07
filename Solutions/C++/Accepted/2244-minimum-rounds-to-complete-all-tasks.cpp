/*
Problem Title: 2244 - Minimum Rounds to Complete All Tasks
Lang: C++
Runtime: 602 ms
Memory: 103.7 MB
Problem Url: https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks
Submission Url: https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/submissions/870823592
*/

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> task_freq;
        int minimum_round = 0;

        for(int task : tasks){
            task_freq[task] += 1;
        }

        for(auto ele : task_freq) {
            int taskCount = ele.second;
            if(taskCount == 1) {
                return -1;
            }
            minimum_round += (taskCount / 3) + (taskCount%3 > 0 ? 1 : 0);
        }
        
        return minimum_round;
    }
};