/* Question: Ransom Note
 * Lang: cpp
 * Runtime: 26 ms
 * Memory: 8.8 MB
 * Question Url: https://leetcode.com/problems/ransom-note
 * Submission Url:
 * https://leetcode.com/problems/ransom-note/submissions/783218983
 */

class Solution {
public:
  bool canConstruct(string ransomNote, string magazine) {
    vector<int> fr(26, 0);
    for (char ch : magazine) {
      fr[ch - 'a']++;
    }
    for (char ch : ransomNote) {
      if (fr[ch - 'a'] == 0) {
        return false;
      }
      fr[ch - 'a']--;
    }
    return true;
  }
};
