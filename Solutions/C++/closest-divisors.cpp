/* Question: Closest Divisors
 * Lang: cpp
 * Runtime: 4 ms
 * Memory: 8.4 MB
 * Question Url: https://leetcode.com/problems/closest-divisors
 * Submission Url:
 * https://leetcode.com/problems/closest-divisors/submissions/305939350
 */

class Solution {
public:
  struct primeFactorization {

    // to store the prime factor
    // and its highest power
    int countOfPf, primeFactor;
  };
  void generateDivisors(int curIndex, long long curDivisor,
                        vector<primeFactorization> &arr, vector<int> &ans,
                        int num) {

    // Base case i.e. we do not have more
    // primeFactors to include
    if (curIndex == arr.size()) {

      int d2 = num / curDivisor;

      if (ans.size() == 0) {
        ans.push_back(d2);
        ans.push_back(curDivisor);
      } else {

        if (abs(ans[0] - ans[1]) > abs(d2 - curDivisor)) {
          ans[0] = d2;
          ans[1] = curDivisor;
        }
      }

      return;
    }

    for (int i = 0; i <= arr[curIndex].countOfPf; ++i) {
      generateDivisors(curIndex + 1, curDivisor, arr, ans, num);
      curDivisor *= arr[curIndex].primeFactor;
    }
  }
  void findDivisors(int n, vector<int> &ans) {

    // To store the prime factors along
    // with their highest power
    vector<primeFactorization> arr;
    int num = n;
    // Finding prime factorization of n
    for (int i = 2; i * i <= n; ++i) {
      if (n % i == 0) {
        int count = 0;
        while (n % i == 0) {
          n /= i;
          count += 1;
        }

        // For every prime factor we are storing
        // count of it's occurenceand itself.
        arr.push_back({count, i});
      }
    }

    // If n is prime
    if (n > 1) {
      arr.push_back({1, n});
    }

    int curIndex = 0, curDivisor = 1;

    // Generate all the divisors
    generateDivisors(curIndex, curDivisor, arr, ans, num);
  }

  vector<int> closestDivisors(int num) {

    vector<int> ans;

    findDivisors(num + 1, ans);
    findDivisors(num + 2, ans);

    return ans;
  }
};
