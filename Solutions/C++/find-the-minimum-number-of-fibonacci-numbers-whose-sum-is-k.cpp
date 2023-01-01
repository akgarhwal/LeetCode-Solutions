/* Question: Find the Minimum Number of Fibonacci Numbers Whose Sum Is K
 * Lang: cpp
 * Runtime: 4 ms
 * Memory: 6.4 MB
 * Question Url:
 * https://leetcode.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k
 * Submission Url:
 * https://leetcode.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/submissions/326614482
 */

class Solution {
public:
  int findMinFibonacciNumbers(int k) {
    vector<int> fbs;
    fbs.push_back(1);
    fbs.push_back(1);
    int N = 46;
    for (int i = 2; i < N; i++) {
      fbs.push_back(fbs[i - 1] + fbs[i - 2]);
    }

    int ans = 0, ind = 45;
    while (k != 0) {
      if (k >= fbs[ind]) {
        k = k - ((k / fbs[ind]) * fbs[ind]);
        ans++;
      }
      ind--;
    }

    return ans;
  }
};
