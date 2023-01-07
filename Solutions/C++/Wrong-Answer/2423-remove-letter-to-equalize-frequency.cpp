/*
Problem Title: 2423 - Remove Letter To Equalize Frequency
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/remove-letter-to-equalize-frequency
Submission Url: https://leetcode.com/problems/remove-letter-to-equalize-frequency/submissions/869783653
*/

class Solution {
public:
    bool equalFrequency(string word) {
        unordered_map<char,int> mp;
        for(char ch: word){
            mp[ch] += 1;
        }
        int mi = INT_MAX, mx =INT_MIN, sum = 0, chCount = 0;
        for(auto kv : mp) {
            
            int count = kv.second;
            cout<<kv.first<<" - "<<count<<endl;

            mi = min(mi, count);
            mx = max(mx, count);
            sum += count;
            chCount += 1;
        }

        if((mx-1 == mi and sum-1 == mi*chCount) or (mx == mi and mx == 1) or (mi==1 and sum-1 == mx*(chCount-1))) {
            return true;
        }
        return false;
    }
};