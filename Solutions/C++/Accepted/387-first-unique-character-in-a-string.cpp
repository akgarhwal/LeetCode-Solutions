/*
Problem Title: 387 - First Unique Character in a String
Lang: C++
Runtime: 26 ms
Memory: 10.4 MB
Problem Url: https://leetcode.com/problems/first-unique-character-in-a-string
Submission Url: https://leetcode.com/problems/first-unique-character-in-a-string/submissions/774732438
*/

class Solution {
public:
    int firstUniqChar(string s) {
        vector<pair<int,int>> memory(26,{0,0});
        
        for(int index = 0; index < s.size(); index++) {
            memory[s[index]-'a'].first += 1;
            if(memory[s[index]-'a'].first == 1){
                memory[s[index] - 'a'].second = index;
            }
        }
        
        int ans = INT_MAX;
        for(auto pi : memory){
            if(pi.first == 1){
                ans = min(ans, pi.second);
            }
        }
        
        ans = ans == INT_MAX ? -1 : ans;
        
        return ans;
    }
};