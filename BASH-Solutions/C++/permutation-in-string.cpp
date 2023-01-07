/* Question: Permutation in String
 * Lang: cpp
 * Runtime: 48 ms
 * Memory: 30 MB
 * Question Url: https://leetcode.com/problems/permutation-in-string
 * Submission Url:
 * https://leetcode.com/problems/permutation-in-string/submissions/341135883
 */

class Solution {
public:
  bool EQL(vector<int> arr, vector<int> arr2) {
    for (int i = 0; i < 26; i++) {
      if (arr[i] != arr2[i]) {
        return false;
      }
    }
    return true;
  }
  bool checkInclusion(string s1, string s2) {
    if (s1.size() > s2.size())
      return false;
    vector<int> arr(26, 0);
    for (char ch : s1) {
      arr[ch - 'a']++;
    }

    vector<int> arr2(26, 0);
    int ind = 0;
    while (ind < s1.size()) {
      arr2[s2[ind++] - 'a']++;
    }
    if (EQL(arr, arr2)) {
      return true;
    }
    while (ind < s2.size()) {
      arr2[s2[ind] - 'a']++;
      arr2[s2[ind - s1.size()] - 'a']--;
      if (EQL(arr, arr2)) {
        return true;
      }
      ind++;
    }
    return false;
  }
};
