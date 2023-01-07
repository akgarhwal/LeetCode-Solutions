/* Question: Maximum Units on a Truck
 * Lang: cpp
 * Runtime: 216 ms
 * Memory: 49.4 MB
 * Question Url: https://leetcode.com/problems/maximum-units-on-a-truck
 * Submission Url:
 * https://leetcode.com/problems/maximum-units-on-a-truck/submissions/507689555
 */

class Solution {
public:
  int static sortBy(vector<int> a, vector<int> b) { return a[1] < b[1]; }

  int maximumUnits(vector<vector<int>> &boxTypes, int truckSize) {

    sort(boxTypes.begin(), boxTypes.end(), sortBy);

    int ans = 0;
    for (int i = boxTypes.size() - 1; i >= 0; i--) {
      int count = min(truckSize, boxTypes[i][0]);
      ans += boxTypes[i][1] * count;
      truckSize -= count;
    }
    return ans;
  }
};
