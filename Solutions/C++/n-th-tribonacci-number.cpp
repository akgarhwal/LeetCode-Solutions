/* Question: N-th Tribonacci Number
 * Lang: cpp
 * Runtime: 0 ms
 * Memory: 6 MB
 * Question Url: https://leetcode.com/problems/n-th-tribonacci-number
 * Submission Url:
 * https://leetcode.com/problems/n-th-tribonacci-number/submissions/592472907
 */

class Solution {
public:
  int tribonacci(int n) {
    vector<int> fibo(n + 3, 0);
    fibo[0] = 0;
    fibo[1] = 1;
    fibo[2] = 1;

    for (int index = 3; index <= n; index++) {
      fibo[index] = fibo[index - 1] + fibo[index - 2] + fibo[index - 3];
    }
    return fibo[n];
  }
};
