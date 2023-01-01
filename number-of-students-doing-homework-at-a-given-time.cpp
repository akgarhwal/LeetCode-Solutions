/* Question: Number of Students Doing Homework at a Given Time
 * Lang: cpp
 * Runtime: 12 ms
 * Memory: 11 MB
 * Question Url:
 * https://leetcode.com/problems/number-of-students-doing-homework-at-a-given-time
 * Submission Url:
 * https://leetcode.com/problems/number-of-students-doing-homework-at-a-given-time/submissions/340471581
 */

class Solution {
public:
  int busyStudent(vector<int> &startTime, vector<int> &endTime, int queryTime) {
    int ans = 0;
    for (int i = 0; i < startTime.size(); i++) {
      if (startTime[i] <= queryTime and endTime[i] >= queryTime) {
        ans++;
      }
    }
    return ans;
  }
};
