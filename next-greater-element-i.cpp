/* Question: Next Greater Element I
 * Lang: cpp
 * Runtime: 6 ms
 * Memory: 9 MB
 * Question Url: https://leetcode.com/problems/next-greater-element-i
 * Submission Url:
 * https://leetcode.com/problems/next-greater-element-i/submissions/769968139
 */

class Solution {
public:
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    map<int, int> mp;
    for (int i = 0; i < nums2.size(); i++) {
      for (int j = i + 1; j < nums2.size(); j++) {

        if (nums2[j] > nums2[i]) {
          mp[nums2[i]] = nums2[j];
          break;
        }
      }
    }
    vector<int> ans(nums1.size(), -1);
    for (int i = 0; i < nums1.size(); i++) {

      if (mp.find(nums1[i]) != mp.end()) {
        ans[i] = mp[nums1[i]];
      }
    }
    return ans;
  }
};
