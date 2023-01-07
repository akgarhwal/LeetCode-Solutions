/* Question: Find the Student that Will Replace the Chalk
 * Lang: cpp
 * Runtime: 128 ms
 * Memory: 74.3 MB
 * Question Url:
 * https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk
 * Submission Url:
 * https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/submissions/506820601
 */

class Solution {
public:
  int chalkReplacer(vector<int> &chalk, int k) {
    long sum = 0;
    for (int x : chalk) {
      sum += (long)x;
    }

    k = k % sum;

    int ans = 0;
    for (int i = 0; i < chalk.size(); i++) {
      k = k - chalk[i];
      if (k < 0) {
        ans = i;
        break;
      }
    }
    return ans;
  }
};
