/* Question: Number of Subarrays with Bounded Maximum
 * Lang: cpp
 * Runtime: 40 ms
 * Memory: 32.9 MB
 * Question Url:
 * https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum
 * Submission Url:
 * https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/submissions/509278112
 */

class Solution {
public:
  int numSubarrayBoundedMax(vector<int> &nums, int left, int right) {
    int n = 0, sc = 0, ans = 0;
    queue<int> q;
    for (int x : nums) {

      if (x < left) {
        sc++;
      } else if (x > right) {
        q.push(sc);
        if (n > 0) {
          n += sc;
          // cout<<n<<sc<<endl;
          ans += (n * (n + 1)) >> 1;
          while (!q.empty()) {
            int f = q.front();
            // cout<<"f"<<f<<endl;
            q.pop();
            ans -= (f * (f + 1)) >> 1;
          }
        }
        while (!q.empty()) {
          q.pop();
        }
        n = 0;
        sc = 0;
      } else {
        n += sc;
        n += 1;
        if (sc > 0)
          q.push(sc);
        sc = 0;
      }
    }
    q.push(sc);
    if (n > 0) {
      n += sc;
      ans += (n * (n + 1)) >> 1;
      while (!q.empty()) {
        int f = q.front();
        q.pop();
        ans -= (f * (f + 1)) >> 1;
      }
    }
    return ans;
  }
};
/*
[2,1,4,3]
2
3
[2,1,1,1,3,1,1,2,4,1,1,1,1,2,3]
2
3
[16,69,88,85,79,87,37,33,39,34]
55
57
[2,1,4,3]
4
5
[2,1,4,3]
0
0
*/
