/* Question: First Bad Version
 * Lang: cpp
 * Runtime: 5 ms
 * Memory: 5.8 MB
 * Question Url: https://leetcode.com/problems/first-bad-version
 * Submission Url:
 * https://leetcode.com/problems/first-bad-version/submissions/768107414
 */

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
  int firstBadVersion(int n) {
    int ans = 1;
    int low = 0, high = n;
    while (low <= high) {

      int mid = low + (high - low) / 2;

      if (isBadVersion(mid)) {
        high = mid - 1;
        ans = mid;
      } else {
        low = mid + 1;
      }
    }
    return ans;
  }
};
