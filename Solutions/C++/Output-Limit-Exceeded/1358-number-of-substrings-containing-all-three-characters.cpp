/*
Problem Title: 1358 - Number of Substrings Containing All Three Characters
Lang: C++
Runtime: N/A
Memory: N/A
Problem Url: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters
Submission Url: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/submissions/305968400
*/

class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        
        int first = 0, second = 0;
        map<char, int> mp;
        int len = s.size();
        
        while(first < len){
            
            
            while(second < len && mp.size() < 3){
                
                if(mp.count(s[second]) > 0){
                    
                    mp[s[second]] += 1;
                    
                }
                else{
                    mp.insert({s[second], 1});                    
                }
                second += 1;
            }
            
            if(mp.size() == 3){
                
                cout<<first<<" -- "<<second<< endl;
                ans += (len-second+1);
                
            }
            
            if(mp[s[first]] == 1){
                mp.erase(s[first]);
            }
            else{
                mp[s[first]] -= 1;
            }
            
            first += 1;
            
        }
        return ans;
    }
};