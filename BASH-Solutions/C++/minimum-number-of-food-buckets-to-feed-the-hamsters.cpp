/* Question: Minimum Number of Food Buckets to Feed the Hamsters
 * Lang: cpp
 * Runtime: 28 ms
 * Memory: 10.5 MB
 * Question Url:
 * https://leetcode.com/problems/minimum-number-of-food-buckets-to-feed-the-hamsters
 * Submission Url:
 * https://leetcode.com/problems/minimum-number-of-food-buckets-to-feed-the-hamsters/submissions/593432517
 */

class Solution {
public:
  int minimumBuckets(string street) {

    for (int i = 0; i < street.size(); i++) {

      if (street[i] == 'H' and i > 0 and street[i - 1] == 'B') {
        street[i] = 'X';
      } else if (street[i] == '.' and i > 0 and street[i - 1] == 'H' and
                 i < street.size() - 1 and street[i + 1] == 'H') {
        street[i] = 'B';
        street[i + 1] = 'X';
        street[i - 1] = 'X';
      } else if (street[i] == 'H' and i < street.size() - 1 and
                 street[i + 1] == '.') {
        street[i + 1] = 'B';
        street[i] = 'X';
      } else if (street[i] == 'H' and i > 0 and street[i - 1] == '.') {
        street[i - 1] = 'B';
        street[i] = 'X';
      }
      // else if (street[i] == 'H' and i == street.size()-1 and i > 0 and
      // street[i-1] > '.'){ street[i-1] = 'B'; street[i] = 'X';
      // }
    }
    int ans = 0;
    for (char x : street) {
      if (x == 'H') {
        return -1;
      }
      ans += (x == 'B');
    }
    return ans;
  }
};
