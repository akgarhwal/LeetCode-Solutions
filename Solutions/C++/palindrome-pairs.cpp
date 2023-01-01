/* Question: Palindrome Pairs
 * Lang: cpp
 * Runtime: 248 ms
 * Memory: 73.5 MB
 * Question Url: https://leetcode.com/problems/palindrome-pairs
 * Submission Url:
 * https://leetcode.com/problems/palindrome-pairs/submissions/507315279
 */

class Solution {
public:
  vector<vector<int>> palindromePairs(vector<string> &words) {
    vector<vector<int>> ans;

    unordered_map<string, int> mp;
    for (int i = 0; i < words.size(); i++) {
      mp[words[i]] = i;
    }

    for (int i = 0; i < words.size(); i++) {
      for (int j = 0; j < words[i].size(); j++) {
        string s1 = words[i].substr(0, j);
        if (isPalin(s1)) {
          string s2 = words[i].substr(j);
          reverse(s2.begin(), s2.end());
          if (mp.find(s2) != mp.end() and mp[s2] != i) {
            vector<int> pair(2, 0);
            pair[1] = i;
            pair[0] = mp[s2];
            ans.push_back(pair);
          }
        }

        s1 = words[i].substr(j);
        if (isPalin(s1)) {
          string s2 = words[i].substr(0, j);
          reverse(s2.begin(), s2.end());
          if (mp.find(s2) != mp.end() and mp[s2] != i) {
            vector<int> pair(2, 0);
            pair[0] = i;
            pair[1] = mp[s2];
            ans.push_back(pair);
          }
        }
      }
    }

    if (mp.find("") != mp.end()) {
      for (int i = 0; i < words.size(); i++) {
        if (isPalin(words[i])) {
          if (mp[""] != i) {
            vector<int> pair(2, 0);
            pair[1] = i;
            pair[0] = mp[""];
            ans.push_back(pair);
          }
        }
      }
    }

    return ans;
  }

  bool isPalin(string s) {
    int n = s.size();
    for (int i = 0; i < n / 2; i++) {
      if (s[i] != s[n - 1 - i]) {
        return false;
      }
    }
    return true;
  }
};
