/* Question: Maximum Sum Circular Subarray
 * Lang: cpp
 * Runtime: 1388 ms
 * Memory: 43.1 MB
 * Question Url: https://leetcode.com/problems/maximum-sum-circular-subarray
 * Submission Url:
 * https://leetcode.com/problems/maximum-sum-circular-subarray/submissions/339955239
 */

class Solution {
public:
  int maxSubarraySumCircular(vector<int> &A) {
    int ans1 = INT_MIN, st = 0, sum = 0;
    vector<int> ss(2 * A.size() + 1, 0);
    for (int i = 0; i < 2 * A.size(); i++) {
      ss[i + 1] = ss[i] + A[i % A.size()];

      if (i - st >= A.size()) {
        sum -= A[st % A.size()];
        ans1 = max(ans1, sum);
        st++;
        int temp = ss[st + 1], mi_ind = st, di = st;
        while (st <= i) {
          if (ss[st + 1] < temp) {
            temp = ss[st + 1];
            mi_ind = st;
          }
          st++;
        }
        st = mi_ind + 1;
        while (di < st) {
          sum -= A[di % A.size()];
          ans1 = max(ans1, sum);
          di++;
        }
      }
      sum += A[i % A.size()];
      // cout<<i<<" == "<<st<< " " << sum << endl;
      ans1 = max(ans1, sum);
      if (sum <= 0) {
        sum = 0;
        st = i + 1;
        // cout<<i<<endl;
      }
    }

    return ans1;
  }
};
