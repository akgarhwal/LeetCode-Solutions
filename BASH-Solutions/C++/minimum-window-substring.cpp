/* Question: Minimum Window Substring
 * Lang: cpp
 * Runtime: 448 ms
 * Memory: 293 MB
 * Question Url: https://leetcode.com/problems/minimum-window-substring
 * Submission Url:
 * https://leetcode.com/problems/minimum-window-substring/submissions/503798231
 */

class Solution {
public:
  bool isEqual(vector<int> ta, vector<int> sa) {
    for (int i = 0; i < 52; i++) {
      if (ta[i] > sa[i]) {
        return false;
      }
    }
    return true;
  }
  string minWindow(string s, string t) {

    vector<int> ta(52, 0);
    for (char ch : t) {
      if (ch >= 'A' and ch <= 'Z') {
        ta[ch - 'A' + 26]++;
      } else {
        ta[ch - 'a']++;
      }
    }

    vector<int> sa(52, 0);
    int first = 0, second = 0, n = s.size();
    int mi = INT_MAX;
    string ans = "";
    while (first < n) {

      while (isEqual(ta, sa) == false and second < n) {
        char ch = s[second];
        if (ch >= 'A' and ch <= 'Z') {
          sa[ch - 'A' + 26]++;
        } else {
          sa[ch - 'a']++;
        }
        second++;
      }
      if (isEqual(ta, sa) and mi > second - first) {
        mi = second - first;
        ans = s.substr(first, mi);
      }
      char ch = s[first++];
      if (ch >= 'A' and ch <= 'Z') {
        sa[ch - 'A' + 26]--;
      } else {
        sa[ch - 'a']--;
      }
    }
    return ans;
  }
};
